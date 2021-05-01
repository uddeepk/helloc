/*ex 3-6: itoa, converts n to characters in s , and pads for required width */

#include <stdio.h>
#include <string.h>

void reverse(char * s) ;
void itoa(int n, char s[], int width);

int main () {
  char numString[100];
  int number, fieldWidth;
  printf("Enter the number, and the field width: ");
  scanf("%d %d", &number, &fieldWidth);
  itoa(number, numString, fieldWidth);
  printf("%s\n", numString);
  return 0;
}

void itoa(int n, char s[], int width) {
  int i, sign;

  if((sign = n) <0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n/=10) > 0);
  if (sign < 0)
    s[i++] = '-';
  // Enter required spaces
  while ( i < width) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}


void reverse(char * s) {
  char *begin = s, *end = s, temp;
  int len, i;

  len = strlen(s);
  //printf("%d\n",len);
  for ( i = 0 ; i < len - 1; ++i )
    end++;

  for ( i = 0 ; i < len / 2 ; ++i) {
    temp = *end;
    *end = *begin;
    *begin = temp;

    ++begin;
    --end;
  }
}
