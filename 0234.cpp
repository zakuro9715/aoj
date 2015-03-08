#include<iostream>

using namespace std;

int W, H, M, d[10][10];

int dfs(int x, int y, int m, int a, int b)
{
  if(dp[x][y][m] != INF)
    return dp[x][y][m];
  m--;
  if(m == 0)
    return INF;
  if(y == H - 1)
    return d[y][x] < 0 ? -d[y][x] : 0;

  
  if(d[y][x] > 0)
  {
    m += d[y][x];
  }
}

int main()
{
loop:
  int o, f, res;
  cin >> W >> H >> f >> M >> o;
  for(int y = 0; y < H; y++)
    for(int x = 0; x < W; x++)
      cin >> d[y][x];
  for(int x = 0; x < W; x++)
    res = max(res, dfs(x, y, f, o));
  
  if(res == -1)
    cout << "NA" << endl;
  else
    cout << res << endl;
}
