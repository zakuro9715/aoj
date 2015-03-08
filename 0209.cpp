#include<iostream>
#include<utility>
#include<algorithm>
#define INF 1000000000
using namespace std;

typedef pair<int, int> point;
point pinf = point(INF, INF);
int win[100][100], pic[50][50], n, m;

point match(int sx, int sy)
{
  bool b[] = {true, true, true, true};
  int p[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
  for(int y = 0; y < m; y++)
  {
    for(int x = 0; x < m; x++)
    {
      int t[] = {pic[y][x], pic[x][m - y - 1], pic[m - x - 1][y], pic[m - y - 1][m - x - 1]};
      for(int i = 0; i < 4; i++)
      {
        if(t[i] == -1)
          continue;
        if(p[i][0] == -1)
        {
          p[i][0] = sx + x;
          p[i][1] = sy + y;
        }
        if(win[sy + y][sx + x] != t[i])
          b[i] = false;
      }
    }
  }
  point mp = pinf;
  for(int i = 0; i < 4; i++)
    if(b[i])
      mp = min(mp, point(p[i][1], p[i][0]));
  return mp;
}

int main()
{
loop:
  cin >> n >> m;
  if(!n)
    return 0;
  int tmp;
  for(int y = 0; y < n; y++)
  {
    for(int x = 0; x < n; x++)
    {
      cin >> tmp;
      win[y][x] = tmp;
    }
  }
  for(int y = 0; y < m; y++)
  {
    for(int x = 0; x < m; x++)
    {
      cin >> tmp;
      pic[y][x] = tmp;
    }
  }
  point p = pinf;
  for(int y = 0; y <= n - m; y++)
    for(int x = 0; x <= n - m; x++)
      p = min(p, match(x, y));
  if(p == pinf)
    cout << "NA" << endl;
  else
    cout << p.second + 1 << " " << p.first + 1 << endl;
  goto loop;
}
