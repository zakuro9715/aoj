#include<iostream>
#include<queue>
using namespace std;

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, W, H;
bool mem[50][50];

int dfs(int x, int y)
{
  if(!mem[y][x])
    return 0;
  mem[y][x] = 0;
  for(int i = 0; i < 8; i++)
  {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if(tx >= 0 && tx < W && ty >= 0 && ty < H && mem[ty][tx])
      dfs(tx, ty);
  }
  return 1;
}

int main()
{
loop:
  int ans = 0;
  for(int y = 0; y < 50; y++)
    for(int x = 0; x < 50; x++)
      mem[y][x] = 0;
  cin >> W >> H;
  if(!W)
    return 0;
  for(int y = 0; y < H; y++)
    for(int x = 0; x < W; x++)
      cin >> mem[y][x];
  for(int y = 0; y < H; y++)
    for(int x = 0; x < W; x++)
      ans += dfs(x, y);
  cout << ans << endl;
  goto loop;
}
