#include<cstdio>

using namespace std;

int main()
{
  int num;
  double weight, height;
  while(scanf("%d,%lf,%lf", &num, &weight, &height) != EOF)
  {
    if(weight / (height * height) >= 25.0)
    {
      printf("%d\n", num);
    }
  }
  return 0;
}
