// WAP to count blanks, tabs, and newlines
#include <stdio.h>

int main()
{
  int blanks = 0, tabs = 0, newlines = 0;
  char c ;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if(c == '\n')
      ++newlines;
    else
      // do nothin
      ;
  }
  printf("%s %d\n", "blanks", blanks);
  printf("%s %d\n","tabs" , tabs);
  printf("%s %d\n", "newlines", newlines);
  return 0;
}
