#include<stdio.h>
#include<math.h>
int main()
{
  int d[] = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
  int ans[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int n, i, b = 0;
  while(scanf("%d", &n) != EOF)
  {
    for(i = 9; i >= 0; i--)
    {
      d[9 - i] = pow(2, i);
      ans[i] = 0;
    }
    b = 0;
    for(i = 0; i < 10; i++)
    {
      if(d[i] <= n)
      {
        n -= d[i];
        ans[i] = 1;
      }
    }
    for(i = 9; i >= 0; i--)
    {
      if(ans[i])
      {
        if(b)
          printf(" ");
        else
          b = 1;
        printf("%d", d[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
