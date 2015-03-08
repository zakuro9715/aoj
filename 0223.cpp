#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

bool d[52][52][52][52];
int X, Y, tx, ty, kx, ky;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, mem[52][52];

int main()
{
loop:
  cin >> X >> Y;
  if(!X)
    return 0;
  cin >> tx >> ty >> kx >> ky;
  for(int y = 1; y <= Y; y++)
  {
    for(int x = 1; x <= X; x++)
    {
      int a;
      cin >> a;
      mem[y][x] = a;
    }
    mem[y][0] = 1;
    mem[y][X + 1] = 1;
  }
  for(int x = 0; x <= X + 1; x++)
  {
    mem[0][x] = 1;
    mem[Y + 1][x] = 1;
  }

  fill_n((bool*)d, 52 * 52 * 52 * 52, false);
  
  queue<int> q;
  q.push(tx);
  q.push(ty);
  q.push(kx);
  q.push(ky);
  q.push(0);
  while(!q.empty())
  {
    int x1 = q.front(); q.pop();
    int y1 = q.front(); q.pop();
    int x2 = q.front(); q.pop();
    int y2 = q.front(); q.pop();
    int n = q.front(); q.pop();
    
    if(n > 100)
    {
      break;
    }
    
    if(y1 == y2 && x1 == x2)
    {
      cout << n << endl;
      goto loop;
    }

    for(int i = 0; i < 4; i++)
    {
      int tx1 = x1 + dx[i];
      int ty1 = y1 + dy[i];
      int tx2 = x2 - dx[i];
      int ty2 = y2 - dy[i];

      if(mem[ty1][tx1])
      {
        tx1 = x1;
        ty1 = y1;
      }
      if(mem[ty2][tx2])
      {
        tx2 = x2;
        ty2 = y2;
      }
      if(d[tx1][ty1][tx2][ty2])
        continue; 

      d[tx1][ty1][tx2][ty2] = true;
      q.push(tx1);
      q.push(ty1);
      q.push(tx2);
      q.push(ty2);
      q.push(n + 1);
    }
  }
  cout << "NA" << endl;
  goto loop;
}
