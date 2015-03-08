#include<iostream>
#include<queue>
using namespace std;

int buil[2][103];
bool done[2][103];
int n;

#define INF 1000000000

int bfs()
{
  queue<int> q;
  q.push(0);
  q.push(0);
  q.push(0);
  q.push(1);
  q.push(0);
  q.push(0);

  while(!q.empty())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    int v = q.front(); q.pop();

    while(y + 1 < n && buil[x][y + 1] && buil[x][y] == 1)
      y++;
    while(buil[x][y] == 2)
      y--;

    if(done[x][y])
      continue;

    if(y == n - 1)
      return v;

    done[x][y] = true;

    if(y + 1< n)
    {
      q.push((x + 1) % 2);
      q.push(y + 1);
      q.push(v + 1);
    }

    if(y + 2 < n)
    {
      q.push((x + 1) % 2);
      q.push(y + 2);
      q.push(v + 1);
    }
  }
  return -1;
}


int main()
{
  while(true)
  {
    for(int i = 0; i < 103; i++)
      done[0][i] = done[1][i] = false;

    cin >> n;
    if(!n)
      break;
    for(int j = 0; j < 2; j++)
    {
      for(int i = 0; i < n; i++)
        cin >> buil[j][i];
    }
    int res = bfs();
    if(res == -1)
      cout << "NA" << endl;
    else
      cout << res << endl;
  }
}
