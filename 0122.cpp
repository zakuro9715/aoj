#include<iostream>
using namespace std;

int sp[10][2];
int m[10][10];
int dx[] = {-1, 0, 1, 2, 2, 2, 1, 0, -1, -2, -2, -2},
    dy[] = {2, 2, 2, 1, 0, -1, -2, -2, -2, -1, 0, 1},
    dn = 12;
int N;

bool is_alive(int x, int y, int n)
{
  int sx = sp[n][0], sy = sp[n][1];
  return x >= sx -1 && x <= sx + 1 && y >= sy - 1 && y <= sy + 1;
}

bool dfs(int x, int y, int n)
{
  if(n == N)
    return true;
  if(!is_alive(x, y, n))
    return false; 
  for(int i = 0; i < dn; i++)
  {
    int tx = x + dx[i], ty = y + dy[i];
    if(!(tx >= 0 && tx < 10 && ty >= 0 && ty < 10))
      continue;
    if(dfs(tx, ty, n + 1))
      return true;
  }
  return false;
}

int main()
{
  int sx, sy;
loop:
  cin >> sx >> sy;
  if(!sx)
    return 0;
  sx--; sy--;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> sp[i][0] >> sp[i][1];
    sp[i][0]--; sp[i][1]--;
  }
  for(int i = 0; i < dn; i++)
  {
    int x = sx + dx[i], y = sy + dy[i];
    if(dfs(x, y, 0))
    {
      cout << "OK" << endl;
      goto loop;
    }
  }
  cout << "NA" << endl;
  goto loop;
}
