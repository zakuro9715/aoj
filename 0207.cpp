#include<iostream>
using namespace std;

int block[100][100];
int xs, ys, xg, yg, n, w, h;

bool dfs(int x, int y, int c)
{
  if(block[x][y] != c || block[x][y] == 0)
    return false;
  if(x == xg && y == yg)
    return true;
  bool b = false;
  block[x][y] = 0;
  if(x < w - 1)
    b |= dfs(x + 1, y, c);
  if(x > 0 && !b)
    b |= dfs(x - 1, y, c);
  if(y < h - 1 && !b)
    b |= dfs(x, y + 1, c);
  if(y > 0 && !b)
    b |= dfs(x, y - 1, c);
  return b;
}

int main()
{
  while(true)
  {
    cin >> w >> h;
    if(!w && !h)
      break;
    cin >> xs >> ys
      >> xg >> yg >> n;
    xs--; ys--;
    xg--; yg--;
    
    for(int i = 0; i < n; i++)
    {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      x--; y--;
      block[x][y] = c;
      block[x + 1][y] = c;
      block[x][y + 1] = c;
      block[x + 1][y + 1] = c;
      if(d == 0)
        x += 2;
      else
        y += 2;
      block[x][y] = c;
      block[x + 1][y] = c;
      block[x][y + 1] = c;
      block[x + 1][y + 1] = c;
    }
    if(dfs(xs, ys, block[xs][ys]))
      cout << "OK\n";
    else
      cout << "NG\n";
  }
}
