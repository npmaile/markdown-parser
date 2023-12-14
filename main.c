#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "mdparser/mdparser.h"

void printmdTextWithIndent(mdtext *input, int indent);
void pintmdText(mdtext *input);

void printmdTextWithIndent(mdtext *input, int indent) {
  printf("%*sattribute: %d\n", indent, "", input->attribute);
  printf("%*stext: %s\n", indent, "", input->text);
  for (int i = 0; i < input->innerlen; i++) {
    printmdTextWithIndent(input->inner[i], indent + 1);
  }
}

void printmdText(mdtext *input) { printmdTextWithIndent(input, 0); }

int main() {
  FILE *fp;
  fp = fopen("testfile.md", "r");
  int c;
  if (fp == NULL) {
    perror("Error opening file");
    return (-1);
  }
  do {
    c = fgetc(fp);
    if (feof(fp)) {
      break;
    }
    slurp(c);
  } while (1);
  // fclose(fp);
  printmdText(get());
  return (0);
}

// process by line
//
// # heading 1
// ## heading 2
// ### heading 3
// #### heading 4
// ##### heading 5
// ###### heading 6
// > blockquote
// >> nested blockquote
// 1. list item
// 1. list item also
// 	1. indented list item
// - unordered list
// + unordered list
// * unordered list
// 	 - nested unordered list
// 	 * nested unordered list
// 	 + nested unordered list
/// --- horizontal line
// *** horizontal line
// ___ horizontal line
//
// process by character
//
// ** bold **
// __ bold __
// * italic *
// _italic_
// ***bold and italic***
// ___bold and italic___
// `code`
//
// process by other
//
// ```long code```
// [link title](https://link.location.tld)
// [link title](https://link.location.tld "extra title for link ")
// <https://rawlink.location.tld>
// ![Image title](/some/path)
// [![ImageTitle](/some/image/path)](https://some.link.with.an.image)
