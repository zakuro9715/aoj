#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

bool kaki[200][200];
int N, W, H, S, T;

int cal(int x, int y)
{
  int ans = 0;
  for(int i = 0; i < S; i++)
  {
    for(int j = 0; j < T; j++)
    {
      ans += kaki[i + x][j + y];
    }
  }
  return ans;
}

int main()
{
loop:
  memset(kaki, 0, sizeof kaki);
  cin >> N;
  if(!N)
    return 0;
  cin >> W >> H;
  for(int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    kaki[a][b] = 1;
  }
  cin >> S >> T;
  int ans = 0;
  for(int x = 0; x <= W - S; x++)
   for(int y = 0; y <= H - T; y++)
     ans = max(ans, cal(x, y));
  cout << ans << endl;
  goto loop;
}
