#include<stdio.h>

int main()
{
  int n;
  while(scanf("%d", &n) != -1)
    printf("%d\n", 2 + (2 + n) * (n - 1) / 2);
  return 0;
}
