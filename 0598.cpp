#include<iostream>
#include<string>
using namespace std;

int W, H;
string s[1000], ss[2], joi = "JOI";
int b[1000][1000];

int check(int x, int y)
{
  bool bb = true;
  for(int yy = 0; yy < 2; yy++)
    for(int xx = 0; xx < 2; xx++)
      bb &= s[y + yy][x + xx] == ss[yy][xx];
  return bb ? 1 : 0;
}

int count(int x, int y)
{
  int n = 0, m = 0;
  if(x > 0 && y > 0)
  {
    n += check(x - 1, y - 1);
    m += b[y - 1][x - 1];
  }
  if(x > 0 && y < H - 1)
  {
    n += check(x - 1, y);
    m += b[y][x - 1];
  }
  if(y > 0 && x < W - 1)
  {
    n += check(x, y - 1);
    m += b[y - 1][x];
  }
  if(y < H - 1 && x < W - 1)
  {
    n += check(x, y);
    m += b[y][x];
  }
  return n - m;
}

int main()
{
  int n = 0, ans = -1;
  
  cin >> H >> W;
  for(int i = 0; i < H; i++)
    cin >> s[i];
  cin >> ss[0] >> ss[1];
  
  for(int y = 0; y < H - 1; y++)
    for(int x = 0; x < W - 1; x++)
      n += b[y][x] = check(x, y);
  for(int y = 0; y < H; y++)
  {
    for(int x = 0; x < W; x++)
    {
      auto c = s[y][x];
      for(int i = 0; i < 3; i++)
      {
        s[y][x] = joi[i];
        ans = max(ans, n + count(x, y));
      }
      s[y][x] = c;
    }
  }
  cout << ans << endl;
}
