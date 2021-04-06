#include <stdio.h>

int main() {
  for (  int n = 0 ; n <= 15 ; ++n ) {
    float tempFarenheit = 20 * n;
    float tempCelsius = (5.0f/9.0f) * (tempFarenheit - 32);
    printf("%.2f Farenheit = %.2f Celsius\n", tempFarenheit, tempCelsius);
  }
  return 0;
}
