#include <stdio.h>

#define PI 3.214159

int main()
{
  double radius = 3;
  double circumference = 2 * PI * radius;
  printf("The circumferenc of a circle with radius %.2f is %.2f", radius, circumference);
  return 0;
}
