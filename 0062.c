#include<stdio.h>

int main()
{
  char s[11];
  int d[10][11], i, j;
  while(scanf("%s", s) != -1)
  {
    for(i = 0; i < 10; i++)
      d[0][i] = s[i] - '0';
    for(i = 0; i < 10; i++)
      for(j = 0; j < 9 - i; j++)
        d[(i + 1) % 2][j] = (d[i % 2][j] + d[i % 2][j + 1]) % 10;
    printf("%d\n", d[1][0]);
  }
  return 0;
}
