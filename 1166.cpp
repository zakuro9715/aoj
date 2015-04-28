#include<iostream>
#include<queue>
using namespace std;

int mem[60][60], H, W, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int d[30][30];
int main()
{
loop:
  for(int i = 0; i < 30; i++)
    for(int j = 0; j < 30; j++)
      d[i][j] = 0;
  
  cin >> W >> H;
  if(!W)
    return 0;
  for(int i = 0; i < H * 2 - 1; i++)
  {
    for(int j = 0; j < W  - (i + 1) % 2; j++)
    {
      cin >> mem[i][j];
    }
  }
  d[0][0] = 1;
  queue<int> q;
  q.push(0); q.push(0);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    if(x == W - 1 && y == H - 1)
    {
      cout << d[y][x] << endl;
      goto loop;
    }
    for(int i = 0; i < 4; i++)
    {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if(tx >= 0 && tx < W && ty >= 0 && ty < H && !d[ty][tx])
      {
        if(dx[i] == 1 && !mem[y * 2][x] ||
           dx[i] == -1 && !mem[y * 2][tx] ||
           dy[i] == 1 && !mem[y * 2 + 1][x] ||
           dy[i] == -1 && !mem[ty * 2 + 1][x])
        {
          q.push(tx); q.push(ty);
          d[ty][tx] = d[y][x] + 1;
        }
      }
    }
  }
  cout << 0 << endl;
  goto loop;
}
