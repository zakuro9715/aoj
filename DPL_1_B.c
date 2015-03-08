#include<stdio.h>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int mem[101][10001], N, W, w[101], v[101];

int dp(int i, int j)
{
  int ans;
  if(i == N)
    return 0;
  if(mem[i][j] != -1)
    return mem[i][j];
  if(j < w[i])
    ans = dp(i + 1, j);
  else
    ans = max(dp(i + 1, j), dp(i + 1, j - w[i]) + v[i]); 
  return mem[i][j] = ans;
}

int main()
{
  int i;
  memset(mem, -1, sizeof(mem));
  scanf("%d%d", &N, &W);
  for(i = 0; i < N; i++)
    scanf("%d%d", &v[i], &w[i]);
  printf("%d\n", dp(0, W));
}
