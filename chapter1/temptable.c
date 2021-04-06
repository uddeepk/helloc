#include <stdio.h>
/* This is a comment. 
   Notice how I can write multiple lines
   Anyways this program prints a table of Temperatures in Farenheit, and Temperatures in Celsius */
int main() {
  for (  int n = 0 ; n <= 15 ; ++n ) {
    float tempFarenheit = 20 * n;
    float tempCelsius = (5.0f/9.0f) * (tempFarenheit - 32);
    printf("%.2f Farenheit = %.2f Celsius\n", tempFarenheit, tempCelsius);
  }
  return 0;
}
