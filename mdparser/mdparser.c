#ifndef MDPARSER_C
#define MDPARSER_C 1
#include "mdparser.h"
#include <stdlib.h>
#include <string.h>

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
  // current->inner = malloc(sizeof(mdtext *));

  return current;
}

int stackindex = 0;
mdtext *stack;

mdtext *get() { return stack; }

void processLine(char line[500]) {
  mdtext current = stack[stackindex];
  int i = 0;
  int exitLoop = 0;
  for (char currentChar = line[0]; line[i] != '\0' && exitLoop != 1; i++) {
    switch (currentChar) {
      // heading
    case '#': {
      mdtext *newNode = newMDText(line, MDbold);
      current.innerlen += 1;
      current.inner[current.innerlen - 1] = newNode;
      stackindex += 1;
      stack[stackindex] = *newNode;
      stack[stackindex].text = malloc(sizeof(char) * 500);
      stack[stackindex].text = memcpy(stack[stackindex].text, line, 500);
      stack[stackindex].textlen = 1000; // todo: actually get the text length
      // later process inner stuff
      stackindex -= 1;
      stack[stackindex] = current;
      exitLoop = 1;
      break;
    }
    case '>': {
      mdtext *newNode = newMDText(line, MDblockQuote);
      current.innerlen += 1;
      current.inner[current.innerlen - 1] = newNode;
      stackindex += 1;
      stack[stackindex] = *newNode;
      stack[stackindex].text = malloc(sizeof(char) * 500);
      stack[stackindex].text = memcpy(stack[stackindex].text, line, 500);
      stack[stackindex].textlen = 1000; // todo: actually get the text length
      // later process inner stuff
      stackindex -= 1;
      stack[stackindex] = current;
      exitLoop = 1;
      break;
    }
    default: {
      mdtext *newNode = newMDText(line, MDtext);
      current.innerlen += 1;
      current.inner[current.innerlen - 1] = newNode;
      stackindex += 1;
      stack[stackindex].text = line;
      stack[stackindex].textlen = 1000; // todo: actually get the text length
      stackindex -= 1;
      stack[stackindex] = current;
      exitLoop = 1;
    }
    }
  }
}

void slurp(char c) {
  if (stack == (void *)0) {
    stack = newMDText("", MDtext);
  }
  static char line[500];
  static size_t lineIndex = 0;
  switch (c) {
  case '\n':
    line[lineIndex] = '\0';
    processLine(line);
    lineIndex = 0;
    break;
  default:
    line[lineIndex++] = c;
    break;
  }
}
#endif
