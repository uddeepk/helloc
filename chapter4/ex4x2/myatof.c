#include <ctype.h>
#include <stdio.h>
/* myatof: modified the atof from book;
   convert string s to double */

double getExponent(int n);
//int atoi(char s[]);

double myatof(char s[]) {
  double val, power;
  int i, sign;

  for(i = 0 ;isspace (s[i]); ++i)
    ;
  sign = (s[i] == '-') ? -1 : 1 ;
  if (s[i] == '+' || s[i] == '-')
    ++i;
  for (val = 0.0; isdigit(s[i]); ++i)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }  
  int atoi(char []);
  double atof(char []);
  double exp = 1.0;
  if (s[i] == 'E' || s[i] == 'e') {
    // extension
    ++i;
    int expInt = atoi(&s[i]);
    exp = getExponent(expInt);
  }

  return sign * val / power * exp;
}

double getExponent(int n) {
  double exp = 1;
  while ( n != 0 ) {
    if ( n > 0) {
      exp *= 10.;
      --n;
    } else {
      exp /= 10.;
      ++n;
    }
  }
  return exp;
}
