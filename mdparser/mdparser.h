#ifndef MDPARSER_h
#define MDPARSER_h 1

enum mdAttr { MDtext, MDbold, MDitalic, MDmonospace,MDblockQuote, MDh1, MDh2, MDh3 };

typedef struct mdtext {
  char *text;
  int textlen;
  int innerlen;
  enum mdAttr attribute;
  struct mdtext *inner[100];
} mdtext;

mdtext *newMDText(char input[], enum mdAttr type);

void processLine(char line[500]);

mdtext *get();

  void slurp(char c);

#endif
