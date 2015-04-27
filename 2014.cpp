#include<iostream>
#include<string>
#include<queue>
using namespace std;

int W, H;
string m[50];
int t[50][50];
int v[10000];

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs(int xx, int yy, int n)
{
  int res = 1;
  t[yy][xx] = n;
  queue<int> q;
  q.push(xx);
  q.push(yy);

  while(q.size())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();

    if(m[y][x] != '.')
    {
      if(v[n] == 0)
      {
        if(m[y][x] == 'W')
          v[n] = 1;
        else
          v[n] = 2;
      }
      if(v[n] == 1 && m[y][x] == 'B' || v[n] == 2 && m[y][x] == 'W')
        v[n] = 3;
      continue;
    }

    for(int i = 0; i < 4; i++)
    {
      int tx = x + dx[i], ty = y + dy[i];
      if(0 <= tx && tx < W && 0 <= ty && ty < H && t[ty][tx] <= 0)
      {
        q.push(tx);
        q.push(ty);
        if(!t[ty][tx])
        {
          res++;
          t[ty][tx] = n;
        }
      }
    }
  }
  return res;
}

int main()
{
  while(true)
  {
    cin >> W >> H;
    if(!W)
      break;
    fill((int*)t, (int*)t + 2500, 0);
    fill(v, v + 10000, 0);
    for(int i = 0; i < H; i++)
    {
      cin >> m[i];
      for(int j = 0; j < W; j++)
        if(m[i][j] != '.')
          t[i][j] = -1;
    }

    int a = 11, w = 0, b = 0;
    for(int y = 0; y < H; y++)
    {
      for(int x = 0; x < W; x++)
      {
        if(t[y][x] == 0)
        {
          int r = dfs(x, y, a);
          if(v[a] == 1)
            w += r;
          if(v[a] == 2)
            b += r;
          a++;
        }
      }
    }
    cout << b << " " << w << endl;
  }
}
