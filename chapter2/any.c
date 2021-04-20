/* WAP to write function any(s1, s2), returns first location of s1 where any character of s2 occurs */
#include <stdio.h>

enum { false, true};

int isInString(char c, char s[]);
int any(char s1[], char s2[]);

int main() {
  // Setup to use getlines to get the strings
  char *s1 = NULL, *s2 = NULL;
  size_t len = 0;
  ssize_t nread = 0;

  // Get s1
  nread = getline( &s1, &len, stdin);
  s1[nread - 1] = '\0'; 
  // Get s2
  nread = getline( &s2, &len, stdin);
  s2[nread - 1] = '\0';
  // any (s1, s2)
  printf("%d", any(s1, s2));

  return 0;
}

int isInString(char c, char s[]){
  for ( int i = 0 ; s[i] != '\0' ; ++i ) {
    if ( c == s[i])
      return true;
  }
  return false;
}

int any(char s1[], char s2[]) {
  for (int i = 0 ; s1[i] != '\0' ; ++i) {
    //printf("%d", i);
    if ( isInString(s1[i] , s2))
	 return i;
  }
  return -1;
}
