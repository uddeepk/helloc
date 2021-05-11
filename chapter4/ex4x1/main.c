/* Ex 4-1 : making mystrindex to return the index of the right most match
   Also, I am testing just putting the definitions of the functions in separate sources files.
   Found out that it works. 

   I did 
   cc main.c mygetline.c mystrindex.c -o test.out
*/

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int mystrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*patter to search for*/

/* find all lines matching pattern */
int main ()
{
  char line[MAXLINE];
  int found = 0;
  while (mygetline (line, MAXLINE) > 0) {
    int pos ;
    if ((pos = mystrindex(line, pattern)) >= 0) {
      printf("pos %d: %s", pos, line);
      ++found;
    }
  }
  return found;
}
