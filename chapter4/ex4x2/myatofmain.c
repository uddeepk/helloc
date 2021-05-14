#include <stdio.h>

#define MAXLINE 100

int main()
{
  double num, myatof(char []);
  int atoi(char []);
  char line[MAXLINE];
  scanf("%s", line);
  num = myatof(line);
  printf("%f\n", num);
  return 0;
}
