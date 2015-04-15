#include<stdio.h>

char tmp[10], s[12][13];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int dfs(int x, int y)
{
  int i;
  if(0 > x || x > 11 || 0 > y || y > 11 || s[y][x] != '1')
    return 0;
  s[y][x] = '0';
  for(i = 0; i < 4; i++)
    dfs(x + dx[i], y + dy[i]);
  return 1;
}

int main()
{
  int y, x, i, n;
  while(scanf("%s", s[0]) != -1)
  {
    n = 0;
    for(i = 1; i < 12; i++)
      scanf("%s", s[i]);
    scanf("\n");
    for(y = 0; y < 12; y++)
      for(x = 0; x < 12; x++)
        n += dfs(x, y);
    printf("%d\n", n);
  }
  return 0;
}
