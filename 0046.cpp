#include<cstdio>
using namespace std;

int main()
{
  double max = 0, min = 1000000000;
  double d = 0;
  while(scanf("%lf", &d) != EOF)
  {
    max = max < d ? d : max;
    min = min > d ? d : min;
  }
  printf("%lf\n", max - min);
  return 0;
}
