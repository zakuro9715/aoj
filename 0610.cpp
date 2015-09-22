#include<iostream>
#include<string>
using namespace std;

int main()
{
  int H, W;
  string s[100];
  int ans[100][100];
  fill((int*)ans, (int*)ans + 10000, -1);
  cin >> H >> W;
  for(int y = 0; y < H; y++)
    cin >> s[y];

  for(int y = 0; y < H; y++)
  {
    for(int x = 0; x < W; x++)
    {
      if(s[y][x] != 'c')
        continue;
      for(int t = 0; x + t < W && (t == 0 || s[y][x + t] != 'c'); t++)
        ans[y][x + t] = t;
    }
  }
  for(int y = 0; y < H; y++)
  {
    for(int x = 0; x < W; x++)
      cout << ans[y][x] << (x == W - 1 ? "": " ");
    cout << endl;
  }
}
