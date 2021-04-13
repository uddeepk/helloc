/* WAP to fold long input lines into two or more shorter lines after
   the last non-blank character that occurs before the n-th column*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define LAST_COL 40
void fold(char c[], char ret[]);

int main ()
{
  char *buffer = NULL;
  size_t len = 0;
  ssize_t nread;

  while ((nread = getline(&buffer, &len, stdin)) != -1) {
    char * buffer2;
    fold(buffer, buffer2);
    printf("%s", buffer2);
  }
  return 0;
}

void fold (char c[], char ret[])
{
  // Allot a placekeeper
  // Check if a space character- if yes point to it.
  // check if at limit for columns
  // if yess, see if index is what we need.
  // use index to place new line
  int lastSpaceIndex = -1, lineLength = 0;
  for ( int i = 0 ; c[i] != '\0' ; ++i) {
    ++lineLength;
    if ( c[i] == ' ' || c[i]=='\t')
      lastSpaceIndex = i;
    if ( lineLength > LAST_COL ) {
      if( lastSpaceIndex != -1) {
	c[lastSpaceIndex] = '\n';
	lastSpaceIndex = -1;
      }
      lineLength = 0;
    }
  }
  int offset = 0, i ;
  lineLength = 0;
  for ( i = 0 ; c[i] != '\0' ; ++ i) {
    if ( c[i] == '\n' ) {
      lineLength = 0;
    }
    if ( lineLength > LAST_COL) {
      ret[i+offset] = '\n';
      ++offset;
      lineLength = 0;
    }
    ret[i+offset] = c[i];
    ++lineLength;
  }
  ret[i+offset] = '\0';
}
