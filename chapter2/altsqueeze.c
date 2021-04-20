#include <stdio.h>

enum { false, true};
  
void squeeze ( char s1[], char s2[]) ;
int isInString( char c, char s[]);

int main ()
{
  char* str1 = NULL;
  char* str2 = NULL;
  size_t len = 0;
  ssize_t nread;
  printf("Enter two strings: \n");
  nread = getline( &str1, &len, stdin);
  nread = getline (&str2, &len, stdin);
  squeeze (str1, str2);
  printf ( "The resulting squeezed string is : %s", str1);
  return 0;
}

void squeeze ( char s1[], char s2[]) {
  int i, j;
  for ( i = j = 0; s1[i] != '\0' ; ++i ) {
    if(!isInString(s1[i], s2)) {
	s1[j++] = s1[i];
    }
      
  }
  s1[j] = '\0';
}

int isInString (char c, char s[]) {
  for ( int i = 0 ; s[i] != '\0' ; ++i ) {
    if ( c == s[i])
      return true;
  }
  return false;
}
