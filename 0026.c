#include<stdio.h>

int m[10][10], 
    dx[13] = {0, 0, 1, 0, -1, 1, 1, -1, -1, 0, 2, 0, -2},
    dy[13] = {0, -1, 0, 1, 0, -1, 1, -1, 1, -2, 0, 2, 0};

void drop(int x, int y)
{
  if(x < 0 || x >= 10 || y < 0 || y >= 10)
    return;
  m[y][x]++;
}

int main()
{
  int x, y, s, i, a1 = 0, a2 = 0;
  while(scanf("%d,%d,%d", &x, &y, &s) != -1)
  {
    for(i = 0; i < 5; i++)
      drop(x + dx[i], y + dy[i]);
    if(s == 1)
      continue;
    for(; i < 9; i++)
      drop(x + dx[i], y + dy[i]);
    if(s == 2)
      continue;
    for(; i < 13; i++)
      drop(x + dx[i], y + dy[i]);
  }
  for(y = 0; y < 10; y++)
  {
    for(x = 0; x < 10; x++)
    {
      if(a1 < m[y][x])
        a1 = m[y][x];
      if(!m[y][x])
        a2++;
    }
  }
  printf("%d\n%d\n", a2, a1);
  return 0;
}
