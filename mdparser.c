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
  mdtext *current = stack[arrindex];
}

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
