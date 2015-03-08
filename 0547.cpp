#include<iostream>
using namespace std;
#define RIGHT 0
#define UP 1
#define BOTH 2

int W, H, mem[100][100][3][2];

int dp(int x, int y, int dir, bool turn)
{
  if(x == W - 1 && y == H - 1)
    return 1;
  if(mem[x][y][dir][turn] != -1)
    return mem[x][y][dir][turn];
  int ans = 0;
  if((dir == UP || dir == BOTH || turn) && y < H - 1)
    ans += dp(x, y + 1, UP, dir == UP || dir == BOTH);
  if((dir == RIGHT || dir == BOTH || turn) && x < W - 1)
    ans += dp(x + 1, y, RIGHT, dir == RIGHT || dir == BOTH);
  mem[x][y][dir][turn] = ans % 100000;
  return ans % 100000;
}

int main()
{
  while(1)
  {
    for(int i = 0; i < 100; i++)
      for(int j = 0; j < 100; j++)
        for(int k = 0; k < 3; k++)
          for(int l = 0; l < 2; l++)
            mem[i][j][k][l] = -1;
    cin >> W >> H;
    if(!W && !H)
      break;
    cout << dp(0, 0, BOTH, true) << endl;
  }
}
