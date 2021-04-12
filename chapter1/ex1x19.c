// WAP to print all input lines longer than 80 characters
#include <stdio.h>
#define MAXLINE 1000
int getline( char line[], int maxline);
void copy (char to[], char from[]);
void reverse ( char from[], int len, char to[]);
int main ()
{
  int len;
  int max;
  char line[MAXLINE];
  char rev[MAXLINE];

  max = 0;
  while ( (len = getline(line,MAXLINE)) > 0 ){
    printf("%d %s",len,  line);
    reverse(line, len,rev);
    printf("%s\n", rev);
  }
  return 0;
}

int getline (char s[], int lim)
{
  int i;
  int c;

  for( i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n' ; ) {
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

void reverse(char from[], int len, char to[])
{
  int i;
  for( i = 0; i < len ; ++i) {
    to[i] = from[len - 1 - i];
  }
  to[i] = '\0';
}
