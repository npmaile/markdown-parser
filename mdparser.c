#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

enum mdAttr { MDtext, MDbold, MDitalic, MDmonospace, MDh1, MDh2, MDh3 };

typedef struct mdtext {
  char *text;
  int textlen;
  int innerlen;
  enum mdAttr attribute;
  struct mdtext **inner;
} mdtext;

mdtext *newMDText(char input[], enum mdAttr type) {
  mdtext *current = malloc(sizeof(struct mdtext));
  int i = 0;
  for (; input[i] != '\0'; i++) {
    // we are just using this for counting.
  }
  current->text = malloc(sizeof(char) * i);
  memcpy(current->text, input, i);
  current->textlen = i;
  current->attribute = type;
  return current;
}

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

mdtext *stack;
int stackindex;

void processLine(char line[500]) {
  printf("line 46\n");
  mdtext current = stack[stackindex];
  int i = 0;
  for (char currentChar = line[0]; line[i] != '\0'; i++) {
    switch (currentChar) {
      // heading
    case '#': {
      mdtext *newNode = newMDText(line, MDh1);
      stack[stackindex].innerlen += 1;
      stack[stackindex].inner = realloc(
          &stack[stackindex],
          stack[stackindex].innerlen * sizeof(mdtext *) + sizeof(mdtext));
      stackindex += 1;
      stack[stackindex] = *newNode;
      stack[stackindex].attribute = MDbold;
      stack[stackindex].text = malloc(sizeof(char) * 500);
      stack[stackindex].text = memcpy(stack[stackindex].text, line, 500);
      stack[stackindex].textlen = 1000; // todo: actually get the text length
      stackindex -= 1;
      break;
    }
    default: {
      printf("sdklfjioscv38sd89132\n");
      mdtext *newNode = newMDText(line, MDh1);
      printf("sdf89ewnxcv8923f89\n");
      stack[stackindex].innerlen += 1;
      printf("wo893nscv893\n");
      stack[stackindex].inner = realloc(
          &stack[stackindex],
          stack[stackindex].innerlen * sizeof(mdtext *) + sizeof(mdtext));
      printf("sdf8932we89xcv\n\n\n\n\n\n\n\n\n");
      stackindex += 1;
      printf("skjdfkosdoxcn8w3e\n\n\n");
      stack[stackindex].attribute = MDtext;
      stack[stackindex].text = line;
      printf("892w3nxcv983\n");
      stack[stackindex].textlen = 1000; // todo: actually get the text length
      stackindex -= 1;
    }
    }
  }
  printf("79\n");
}

void slurp(char c) {
  printf("current line %d\n", 83);
  static char line[500];
  static size_t lineIndex = 0;
  switch (c) {
  case '\n':
    printf("sdjfklsj\n");
    line[lineIndex] = '\0';
    printf("before processline\n");
    processLine(line);
    printf("after processline\n");
    lineIndex = 0;
    break;
  default:
    line[lineIndex++] = c;
    break;
  }
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
  printf("line 133\n");
  FILE *fp;
  fp = fopen("testfile.md", "r");
  int c;
  if (fp == NULL) {
    perror("Error opening file");
    return (-1);
  }
  stack = newMDText("", MDtext);
  stackindex = 0;
  do {
    c = fgetc(fp);
    if (feof(fp)) {
      break;
    }
    printf("line 148\n");
    slurp(c);
  } while (1);
  fclose(fp);
  // printmdText(stack[0]);
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
