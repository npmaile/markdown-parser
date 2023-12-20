#ifndef MDPARSER_h
#define MDPARSER_h 1

enum mdAttr {
  // baby
  MDtext,
  // easy
  MDh1,
  MDh2,
  MDh3,
  MDh4,
  MDh5,
  MDh6,
  MDblockQuote,
  MDHorizontalLine,
  // medium
  MDbold,
  MDitalic,
  MDmonospace,
  MDStrikeThrough,
  // hard
  MDLongCode,
  MDUnorderedList,
  MDListItem,
  // impossible
  MDLink,
  MDImage,
  // worse than impossible
  MDTable,
};
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

enum mdAttr GetHeadingLevel(char[500]);

#endif
