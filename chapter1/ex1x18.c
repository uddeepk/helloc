// WAP to print all input lines longer than 80 characters
#include <stdio.h>
#define MAXLINE 1000
int getline( char line[], int maxline);
void copy (char to[], char from[]);
void removeTrailingWhiteSpace(char line[], int len);
int main ()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ( (len = getline(line,MAXLINE)) > 0 ){
      printf("%d %s",len,  line);
      removeTrailingWhiteSpace(line, len);
      printf("%s", line);
  }
  return 0;
}

int getline (char s[], int lim)
{
  int i;
  int c;

  for( i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n' ; ) {
    //    if ( c == '\t' || c == '\b' || c == '\n' || c == ' ')
    //      continue;
    s[i] = c;
    ++i;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
    while ( (to[i] = from[i]) != '\0')
      ++i;
}

void removeTrailingWhiteSpace (char str[], int len)
{
  int i ;
  for ( i = len - 1; i >= 0  ; --i ) {
    char c = str[i];
    if ( c == ' ' || c == '\t' ||  c == '\n')
      continue;
    else
      break;
  }
  ++i;
  str[i] == '\0';
}
