#include <stdio.h>
#include <string.h>

void expand (char* s1, char* s2);

int main() {
  char  s1[1000];// = "a-d";
  char s2[1000];// = NULL;
  scanf("%s", s1);
  expand (s1, s2);
  puts(s2);
  return 0;
}

void expand (char* s1, char* s2) {
  int len = strlen(s1);
  int j = 0;
  for ( int i = 0 ; i < strlen(s1) ; ++i ) {
    // Check for shorthand
    char c1 = s1[i];
    // If shorthand add all letters
    if ( i + 1 < len ) {
      char c2 = s1 [i+1];
      if (c2 == '-' && (i + 2 < len) ) {
	char c3 = s1[i + 2];
	for ( int c = c1 ; c <= c3 ; ++c) {
	  s2[j++] = c;
	}
	i += 2;
	continue;
      }
    }
    s2[j++] = c1;
  }
  s2[j] = '\0';
}
