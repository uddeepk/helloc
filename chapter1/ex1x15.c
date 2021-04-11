#include <stdio.h>

float tempFarenheitToCelsius(float tF);

int main ()
{
  for ( int n = 0 ; n <= 15 ; ++n) {
    float tempFarenheit = 20 * n;
    float tempCelsius = tempFarenheitToCelsius(tempFarenheit);
    printf("%.2f Farenheit = %.2f Celsius\n", tempFarenheit, tempCelsius);
  }
  return 0;
}

float tempFarenheitToCelsius(float tF)
{
  return (5.0f/9.0f)*(tF - 32);
}
