#include <stdio.h>
#include <string.h>

void escape(char* s, char* t);

int main () {
  //char *c = NULL;
  //char *test = NULL
  char c[1000];
  char test[1000];
  // printf("Enter number");
  int i = 0;
  char buf;
  while ( (buf = getchar()) != EOF) {
    test[i] = buf;
    ++i;
  }
  test[i] = '\0';
  escape(c,test);
  printf("%s",c);
  return 0 ;
}

void escape(char*s, char* t) {
  char c;
  size_t i = 0 , j = 0;
  while ( i < strlen (t) && (c = t[i]) != 0) {
      switch(c) {
      case '\t':
      case '\n':
	s[j++] = '\\';
	if ( c == '\t')
	  s[j++] = 't';
	else
	  s[j++] = 'n';
	break;

      default:
	s[j++] = t[i];
	break;
      }
      ++i;
      //break;
      //if (i>20)
         // break;
  }
  s[j] = '\0';
 

}
