#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  double x[3], y[3];
  double dx[2], dy[2];
  while(scanf("%lf,%lf,%lf,%lf,%lf,%lf",  &x[0], &y[0], &x[1], &y[1], &x[2] , &y[2]))
  {

    printf("%lf %lf\n", x[0] + x[2] - x[1], y[0] + y[2] - y[1]);
  }
  return 0;
}
