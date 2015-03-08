#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
int main()
{
  int a, b;
  double x = 0, y = 0, r = 0;
  while(1)
  {
    scanf("%d,%d", &a, &b);
    if(!a && !b)
      break;
    x += sin(r) * a;
    y += cos(r) * a;
    r += b / 180.0 * PI;
  }
  printf("%d\n%d\n", (int)x, (int)y);
  return 0;
}
