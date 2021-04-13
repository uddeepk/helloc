// WAP to detab, replate tabs in input with proper number of blanks
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void detab(char ret[], char s[], int len);

int main ()
{
  char *buffer = NULL;
  size_t len = 0;
  ssize_t nread;

  while ((nread = getline(&buffer, &len, stdin)) != -1) {
    char * buffer2 ;
    detab(buffer2, buffer, len);
    printf("%s\n", buffer2);
  }

  return 0;
}

void detab(char ret[],char s[], int len)
{
  int offset = 0, i = 0;
  for ( ; i < len ;++i) {
    char c = s[i];
    if ( c == '\t') {
      for ( int j = 0 ; j < 4 ; ++j) {
	ret[i+offset + j] = ' ';
      }
      offset += 3;
    }
    else {
      ret [ i + offset] = c;
    }
  }
  ret [ i + offset] = '\0';
}
