#include <stdio.h>
#include <string.h>

void itob(int n, char* s, int b);
char getDigit(int n);
void reverse (char* s);

int main () {
  int inputNumber, base;
  char numberInBase[1000];
  //  itob(15, numberInBase, 16);
  printf("Input a number, and base :");
  scanf("%d %d",&inputNumber, &base);
  itob(inputNumber, numberInBase, base);
  printf("%s\n", numberInBase);
  return 0;
}

void itob(int n, char* s, int b) {
  int i, sign;

  if (( sign = n) < 0) 
    n = -n;
  i = 0;
  do {
    int digit = n % b ;
    char d = getDigit (digit);
    s[i++] = d;
  } while ( (n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  //strrev(s);
  reverse(s);
}

char getDigit(int n) {
  if( n < 10)
    return n + '0';
  else
    return (n - 10) + 'a';
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
