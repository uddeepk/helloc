// Ex1-9 WAP to copy its input to its output, replacing each string of on or more blanks by a single blank.

#include <stdio.h>

int main()
{
  int c;

  while ( 1 ) {
    c = getchar();
    
    if ( c == ' ') {
      putchar(c);
      while ( (c = getchar()) == ' ') {
	// Do nothing. Jut eat up space. But what about EOF ?
      }
    }
    if ( c == EOF)
      break;
    putchar(c);
  }
  return 0;
}
