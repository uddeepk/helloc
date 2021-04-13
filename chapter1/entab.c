#include <stdio.h>
#include <sys/types.h>

void entab(char to [] , char from [], int n);
int main()
{
  char * buffer = NULL;
  size_t len = 0;
  ssize_t nread;

  while ( nread = getline (&buffer, &len, stdin) != -1) {
    char * c ;
    entab(c, buffer, len);
    printf("%s\n", c);
  }
  return 0;
}


void entab(char to [], char from [], int len) {
  int offset = 0;

  for ( int i = 0 ; i <= len ; ++i ) {
    // Look for blanks
    if (from [i] == ' ') {
      int blanks = 0;
      while ( from[i] == ' ' && i < len) {
	++blanks;
	++i;
      }
      int nt = blanks / 4;
      int ns = blanks % 4;
      offset += blanks;
      
      for ( int j = 0 ; j < nt ; ++j) {
	to[i - offset + j] = '\t';
      }
      offset -= nt;
      
      for ( int j = 0 ; j < ns ; ++j) {
	to[i - offset + j] = ' ';
      }
      offset -= ns;

    }
      to[i - offset] = from[i];
  }
}
