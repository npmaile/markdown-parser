#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

enum mdAttr { MDtext, MDbold, MDitalic, MDmonospace, MDh1, MDh2, MDh3 };

typedef struct mdtext {
  char *text;
  int textlen;
  int innerlen;
  enum mdAttr attribute;
  struct mdtext **inner;
} mdtext;

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

mdtext **stack;
void parse(char c) {
  static int arrindex;
  switch (stack[arrindex]->attribute) {
  case MDtext: {
  }
  case MDbold: {
  }
  case MDitalic: {
  }
  case MDmonospace: {
  }
  case MDh1: {
  }
  case MDh2: {
  }
  case MDh3: {
  }
  }
  putchar(c);
  // mdtext *current = stack[arrindex];
}

// # heading 1
// ## heading 2
// ### heading 3
// #### heading 4
// ##### heading 5
// ###### heading 6
// ** bold **
// __ bold __
// * italic *
// _italic_
// ***bold and italic***
// ___bold and italic___
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
// `code`
// ```long code```
// --- horizontal line
// *** horizontal line
// ___ horizontal line
// [link title](https://link.location.tld)
// [link title](https://link.location.tld "extra title for link ")
// <https://rawlink.location.tld>
// ![Image title](/some/path)
// [![ImageTitle](/some/image/path)](https://some.link.with.an.image)

int main() {
  FILE *fp;
  fp = fopen("testfile.md", "r");
  int c;
  if (fp == NULL) {
    perror("Error opening file");
    return (-1);
  }
  stack = malloc(sizeof(mdtext));
  do {
    c = fgetc(fp);
    if (feof(fp)) {
      break;
    }
    parse(c);
  } while (1);
  fclose(fp);
  printmdText(stack[0]);
  return (0);
}

/*
int main() {
  mdtext toprint4;
  toprint4 = (mdtext){"g", 2, 0, MDitalic, NULL};

  mdtext toprint2;
  toprint2 = (mdtext){"a", 2, 1, MDbold};
  toprint2.inner = malloc(sizeof(struct mdtext *) * 1);
  toprint2.innerlen = 1;
  toprint2.inner[0] = &toprint4;

  mdtext toprint3;
  toprint3 = (mdtext){"a", 2, 0, MDh1, NULL};

  mdtext toprint;
  toprint = (mdtext){"a", 2, 0, MDh3, NULL};

  toprint.inner = malloc(sizeof(struct mdtext *) * 2);
  toprint.innerlen = 2;
  toprint.inner[0] = &toprint2; // malloc(sizeof(struct mdtext));
  toprint.inner[1] = &toprint3; // malloc(sizeof(struct mdtext));
  printmdText(&toprint, 0);
}
*/

/*
mdtext{
        inner{
                mdAttr{MDbold}
                text = "hello"
        }
        mdAttr{MDh1}
}
*/
