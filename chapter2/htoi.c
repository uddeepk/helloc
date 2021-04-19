#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int htoi(const char hexstr[]);
int hexToDec(int c);
int main () {
  char *hexNumber = NULL ;
  size_t n = 0;
  size_t len = getline ( &hexNumber, &n, stdin);
  // Debug output
  printf("%d\n",/*strlen(hexNumber));*/htoi(hexNumber));
  return 0;
}
int hexToDec(int c) {
  if ( c >= 'A' && c <= 'Z')
    c = c + 'a' - 'A';

  switch (c) {
  case 'a':
    return 10;
    break;
  case 'b':
    return 11;
    break;
  case 'c':
    return 12;
    break;
  case'd':
    return 13;
    break;
  case 'e':
    return 14;
    break;
  case 'f' :
    return 15;
    break;
  default:
    return c - '0';
  }
}
int htoi(const char hexstr[]) {
  size_t index = 0, len = strlen(hexstr);
  int decimalNumber = 0;
  if(len >= 2 && hexstr[0] == '0' &&
     (hexstr[1] == 'x' || hexstr [1] == 'X'))
    index += 2;

  while ( index < len - 1) {
     int hexD = hexstr[index];
     decimalNumber = decimalNumber * 16 + hexToDec(hexD);
     ++index;
  }
  return decimalNumber;
}
