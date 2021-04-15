/* WAP to check a C program for unmatched parantheses, brackes and braces */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define IN_COMMENT 1
#define OUT_OF_COMMENT 0
#define MAX_CHARS 1000
#define true 1
#define false 0
void getInput(char myinput[]);
void removeComments( char myinput[], char myoutput[]);
int checkValidity( char inputStr[], int *i, char m);
char getMatchChar(char c);

int main()
{
  char  myStr[MAX_CHARS], noComments[MAX_CHARS] ;
  // Get inut
  getInput( myStr);
  // Remove comments
  removeComments( myStr, noComments);
  //  printf( "%s", noComments);

  int i = 0;
  
  if (checkValidity(noComments, &i, 0)) {
    printf("Valid!");
  }
  else {
    printf ("Invalid! Check syntax");
  }
  //printf ("\n");

  //if (printf ("%d\n", f);
  
  // Look for one of the special characters
  // Search for matching character
  // If during this search another special character found,..
  // then recurse using that new character ?
  return 0;
}
void getInput (char myinput[]) {
  int c , index = 0;
  while (( c = getchar()) != EOF) {
    myinput[index++] = c;
  }
  myinput [index] = '\0';
}
void removeComments (char myinput[], char myoutput []) {
  char * buffer = NULL;
  size_t len = 0;
  ssize_t nread;
  int c;
  int state = 0;
  int index = 0;
  for (int i = 0 ; i < strlen(myinput); ++i) {
    c = myinput[i];
    if (state == IN_COMMENT) {
      if ( c == '*') {
	c = myinput[++i];
	if ( c == '/') {
	  state = OUT_OF_COMMENT;
	}
      }
    }
    else {
      if (c == '/') {
	char n = myinput[++i];
	if ( n == '/') {
	  while (( c = myinput[++i]) != '\n');
	}
	else if ( n == '*') {
	  state = IN_COMMENT;
	}
	else {
	  myoutput[index++] = c;
	  myoutput[index++] = n;
	}
      }
      else {
	myoutput[index++] = c;
      }
    }
  }
  myoutput[index] = '\0';

}

int checkValidity(char inputStr[], int * i, char m) {
  
  for (  ;( *i) < strlen(inputStr) ; *i += 1) {
    
    char c = inputStr[*i];
    if ( m == '\'') {
      if ( c == m){
	return true;
      }
      if (c == '\\' ) {
	*i += 2;
      }
      else {
	*i += 1;
      }
      return ((*i) < strlen(inputStr) && m == inputStr[*i]);
    }
    if ( m > 0 ) {
      if ( c == m  ) {
	return true;
      } else if ( c == '}' || c == ']' || c == ')') {
	return false;
      }
    }
    else {
      // Do nothing ?
       if ( c == '}' || c == ']' || c == ')') {
	return false;
      }
    }

    switch (c) {
    case '\\':
      //Ignorenext
      *i += 1;
      continue;
      break;
    case '{':
    case '(':
    case '[':
    case '\"':
    case '\'':
      *i += 1;
      if(!checkValidity( inputStr, i, getMatchChar(c)))
	return false;
      break;
    
    }
    

  }

  return m == 0;
}

char getMatchChar (char c ) {
  switch (c) {
  case '{':
    return '}';
    break;
  case '[':
    return ']';
    break;
    
  case '(':
    return ')';
    break;
  default:
    return c;
    break;
  }
}
