#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

enum mdAttr { MDbold, MDitalic, MDmonospace, MDh1, MDh2, MDh3 };

typedef struct mdtext {
  char *text;
  int textlen;
  enum mdAttr attribute;
} mdText;

typedef struct mdDoc {
  struct mdtext *texts;
} mdDoc;

int main() {
  FILE *fp;
  fp = fopen("testfile.md", "r");
  int c;
  if (fp == NULL) {
    perror("Error opening file");
    return (-1);
  }
  mdDoc *document;
  document = malloc(sizeof(&document));
  do {
    c = fgetc(fp);
    if (feof(fp)) {
      break;
    }
    printf("%c", c);
  } while (1);
  fclose(fp);
  return (0);
}
