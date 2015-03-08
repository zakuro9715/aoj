#include<iostream>
#include<string>
using namespace std;

int H, W;
string s[100];

int dfs(int x, int y, char c)
{
  if(x < 0 || x >= W || y < 0 || y >= H || c != s[y][x])
    return 1;
  s[y][x] = 'A';
  dfs(x + 1, y, c);
  dfs(x - 1, y, c);
  dfs(x, y + 1, c);
  dfs(x, y - 1, c);
  return 1;
}

int main()
{
loop:
  int ans = 0;
  cin >> H >> W;
  if(!H)
    return 0;
  for(int i = 0; i < H; i++)
    cin >> s[i];
  for(int y = 0; y < H; y++)
    for(int x = 0; x < W; x++)
      if(s[y][x] != 'A')
        ans += dfs(x, y, s[y][x]);
  cout << ans << endl;
  goto loop;
}
