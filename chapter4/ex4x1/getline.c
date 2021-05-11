/* getline: return a char[] until it hits new line or EOF*/

/* int getline (char s[], int lim);*/

/*
int getline (char s[], int lim)
{
  int i;
  int c;

  for( i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n' ; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

*/

// I am placing the getline in the book here instead of mine

#include <stdio.h>

int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if ( c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
