#include<iostream>
#include<queue>
#include<string>
using namespace std;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int W, H;
string mem[20];
bool res[20][20];

int dfs(int sx, int sy)
{
  for(int i = 0; i < 20; i++)
    for(int j = 0; j < 20; j++)
      res[i][j] = 0;
  queue<int> q;
  q.push(sx);
  q.push(sy);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    res[y][x] = true;
    for(int i = 0; i < 4; i++)
    {
      
      int tx = x + dx[i];
      int ty = y + dy[i];
      if(tx >= 0 && ty >= 0 && tx < W && ty < H && mem[ty][tx] == '.' && !res[ty][tx])
      {
        q.push(tx);
        q.push(ty);
      }
    }
  }
  int ans = 0;
  for(int y = 0; y < H; y++)
    for(int x = 0; x < W; x++)
      ans += res[y][x];
  return ans;
}

int main()
{
loop:
  for(int i = 0; i < 20; i++)
    mem[i] = "";
  int sx = -1, sy;
  cin >> W >> H;
  if(!(W || H))
    return 0;
  for(int i = 0; i < H; i++)
  {
    cin >> mem[i];
    if(sx != -1)
      continue;
    for(int j = 0; j < W; j++)
    {
      if(mem[i][j] == '@')
      {
        sx = j;
        sy = i;
        break;
      }
    }
  }
  cout << dfs(sx, sy) << endl;
  goto loop;
}
