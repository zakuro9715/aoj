#include<iostream>
#include<queue>
using namespace std;

bool mem[150][150];
int T, N, d[150][150], dx[] = {0, 0, 1, -1, 1, -1}, dy[] = {1, -1, 1, -1, 0, 0};
int bfs(int sx, int sy)
{
  queue<int> q;
  d[sx][sy] = 1;
  q.push(sx);
  q.push(sy);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    for(int i = 0; i < 6; i++)
    {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if(!mem[tx][ty] && d[x][y] <= T && !d[tx][ty])
      {
        d[tx][ty] = d[x][y] + 1;
        q.push(tx);
        q.push(ty);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < 150; i++)
    for(int j = 0; j < 150; j++)
      ans += d[i][j] != 0;
  return ans;
}

int main()
{
loop:
  for(int i = 0; i < 150; i++)
    for(int j = 0; j < 150; j++)
      mem[i][j] = d[i][j] = 0;
  cin >> T >> N;
  if(!T)
    return 0;
  for(int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    mem[a + 75][b + 75] = 1;
  }

  int sx, sy;
  cin >> sx >> sy;
  cout << bfs(sx + 75, sy + 75) << endl;
  goto loop;
}
