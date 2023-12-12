#include <stdio.h>

int main() {
  unsigned int symbols = 0;
  unsigned int controls = 0, latins = 0, digits = 0, operations = 0;
  unsigned int lines = 1;
  unsigned int words = 0;
  char k = 0;
  for (int c = getchar(); c != EOF; c = getchar()) {
    symbols++;
    if (c < 32 || c == 127) {
      controls++;
    } else if (c > 47 && c < 58) {
      digits++;
    } else if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
      latins++;
    } else if (c == 37 || c == 42 || c == 43 || c == 45 || c == 47 || c == 94) {
      operations++;
    }
    switch (c) {
    case '\n':
      lines++;
    case '\t':
    case ' ':
      words += k;
      k = 0;
      break;
    default:
      k = 1;
    }
    putchar(c);
  }
  words += k;
  printf("\nSymbols: %u\nLines: %u\nWords: %u\nControl symbols: %u\nLatin "
         "symbols: %u\nDigits: %u\nOperation symbols: %u\n",
         symbols, lines, words, controls, latins, digits, operations);
  return 0;
}
