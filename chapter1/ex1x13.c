#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  int c, state, wordLength = 0;

  state = OUT;
  while( (c = getchar()) != EOF) {
    if ( c == ' ' || c == '\n' || c == '\t') {
      if (state ) {
	printf("\t%d", wordLength);
	putchar('\n');
	wordLength = 0;
      }
      state = OUT;
    }
    else {
      state = IN;
      putchar(c);
      ++wordLength;
    }
  }
  return 0;
}
