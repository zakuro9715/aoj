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
    if(i % 2)
    {
      for(int j = 0; j < W; j++)
      {
        cin >> mem[i][j * 2];
      }
    }
    else
    {
      for(int j = 0; j < W - 1; j++)
      {
        cin >> mem[i][j * 2 + 1];
      }
    }
  }
  for(int i = 0; i < H * 2 - 1; i++)
  {
    for(int j = 0; j < W * 2 - 1; j++)
      cout << mem[i][j];
    cout << endl;
  }
  d[0][0] = 1;
  queue<int> q;
  q.push(0); q.push(0);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    if(x == W * 2 - 1 && y == H * 2 - 1)
    {
      cout << d[x][y] << endl;
      goto loop;
    }
    for(int i = 0; i < 4; i++)
    {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if(tx >= 0 && tx < W * 2 && ty >= 0 && ty < H * 21&& !d[tx][ty])
      {
   /*     if(dx[i] == 1 && !mem[ty * 2][x] ||
           dx[i] == -1 && !mem[ty * 2][tx] ||
           dy[i] == 1 && !mem[y * 2 + 1][tx] ||
           dy[i] == -1 && !mem[ty * 2 + 1][tx])*/
        if(!mem[ty][tx])
        {
          q.push(tx); q.push(ty);
          d[tx][ty] = d[x][y] + 1;
        }
      }
    }
  }
  cout << 0 << endl;
  goto loop;
}
