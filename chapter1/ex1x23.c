/* WAP to remove all comments from a C program */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define IN_COMMENT 1
#define OUT_OF_COMMENT 0
int main()
{
  char * buffer = NULL;
  size_t len = 0;
  ssize_t nread;
  int c ;
  int state = 0;
    
  while ((c = getchar()) != EOF) {
    if ( state== IN_COMMENT) {
      // Look for end
      if ( c == '*') {
	c = getchar();
	if ( c == '/') {
	  state = OUT_OF_COMMENT;
	}
      }
      // Also, ignore chars
    }
    else {
      // Look for beginning of comment
      if ( c == '/' ) {
	char n = getchar();
	if ( n == '/') {
	  // RUn through till '\n'
	  while (( c = getchar()) != '\n');
	}
	else if (  n == '*') {
	  state = IN_COMMENT;
	}
	else {
	  putchar(c);
	  putchar(n);
	}
      }
      else {
	// Display characters
	putchar (c);
      }
     
    }
  }
  return 0;
}
