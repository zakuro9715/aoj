#include<iostream>
#include<cstring>
using namespace std;

int construct[17][17], dp[17][17], W, H, N;
int main()
{
loop:
  memset(construct, 0, sizeof construct);
  memset(dp, 0, sizeof dp);
  cin >> W >> H;
  if(!W && !H)
    return 0;

  cin >> N;
  for(int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    construct[a][b] = 1;
  }

  dp[0][1] = 1;
  for(int x = 1; x <= W; x++)
  {
    for(int y = 1; y <= H; y++)
    {
      if(construct[x][y])
        continue;
      dp[x][y] = dp[x - 1][y] + dp[x][y - 1];      
    }
  }
  cout << dp[W][H] << endl;
  goto loop;
}
