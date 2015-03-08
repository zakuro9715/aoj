#include<iostream>
#include<string>
#include<queue>
using namespace std;

#define INF 1000000000

string mem[4000], origin[4000];
char N;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, H, W, sx, sy, d[4000][4000];

int dfs(char p)
{
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      d[i][j] = INF;
  queue<int> q;
  q.push(sx);
  q.push(sy);
  d[sy][sx] = 0;
  while(1)
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    if(mem[y][x] == p)
    {
      sx = x;
      sy = y;
      return d[y][x];
    }
    for(int i = 0; i < 4; i++)
    {
      int tx = x + dx[i], ty = y + dy[i];
      if(tx >= 0 && tx < W && ty >= 0 && ty < H && d[ty][tx] == INF && mem[ty][tx] != 'X')
      {
        q.push(tx);
        q.push(ty);
        d[ty][tx] = d[y][x] + 1;
      }
    }
   
  }
}

int main()
{
  cin >> H >> W >> N;
  sx = -1; sy = -1;
  for(int i = 0; i < H; i++)
  {
    cin >> mem[i];
    origin[i] = mem[i];
    if(sx != -1)
      continue;
    for(int j = 0; j < mem[i].length(); j++)
    {
      if(mem[i][j] == 'S')
      {
        sx = j;
        sy = i;
      }
    }
  }
  int ans = 0; 
  for(char i = '1'; i <= N; i++)
  {
    for(int j = 0; j < H; j++)
      mem[j] = origin[j];
    ans += dfs(i);
  }
  cout << ans << endl;
}
