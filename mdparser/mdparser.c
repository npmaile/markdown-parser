#include <stdio.h>
#ifndef MDPARSER_C
#define MDPARSER_C 1
#include "mdparser.h"
#include <stdlib.h>
#include <string.h>
char peekahead(int peekAmount, char input[500]);

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
// ---
// ___
// ***

int stackindex = 0;
mdtext *stack;

mdtext *get() { return stack; }

void processLine(char line[500]) {
  mdtext current = stack[stackindex];
  int i = 0;
  // todo: handle empty lines
  if (line[0] == '\0') {
    return;
  }
  switch (line[0]) {
  case '_': {
    switch (peekahead(1, line)) {
    // either a horizontal line, a bold, or a bold and italic
    case '_': {
      switch (peekahead(2, line)) {
      // either a bold line or bold and italic
      case '_': {
        switch (peekahead(3, line)) {
        // horizontal line
        case '\0': {
          mdtext *newNode = newMDText(line, MDHorizontalLine);
          current.innerlen += 1;
          current.inner[current.innerlen - 1] = newNode;
          return;
        }
        // beginning of a bold and italic
        // todo: find the end of the bold and italic
        default: {
          break;
        }
        }
      }
        // just bold
      default: {
        break;
      }
      }
    };
    // probably a regular line
    case '\0': {
      break;
    }
      // probably
    default: {
      break;
    }
    }
  }
  case '#': {
    enum mdAttr attribute = GetHeadingLevel(line);
    mdtext *newNode = newMDText(line, attribute);
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
  }
  }
}

enum mdAttr GetHeadingLevel(char input[500]) {
  int headingLevel = 0;
  for (int i = 0; i < 500 && input[i] != '\0'; i++) {
    if (input[i] == '#') {
      headingLevel++;
    } else {
      break;
    }
  }
  switch (headingLevel) {
  case 1:
    return MDh1;
  case 2:
    return MDh2;
  case 3:
    return MDh3;
  case 4:
    return MDh4;
  case 5:
    return MDh5;
  case 6:
    return MDh6;
  default:
    return MDh6;
  };
}

char peekahead(int peekAmount, char input[500]) {
  int i = 0;
  for (; i < 500 && i <= peekAmount && input[i] != '\0'; i++) {
    if (i == peekAmount) {
      return input[i];
    }
  }
  return '\0';
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
