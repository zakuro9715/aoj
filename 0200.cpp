#include<iostream>
#include<algorithm>
#define INF (1 << 30)
using namespace std;

int V, E, cost[100][100][2], d[100], done[100];

int dj(int s, int k)
{
  fill(d, d + 100, INF);
  fill(done, done + 100, 0);
  d[s] = 0;

  while(1)
  {
    int v = -1;
    for(int i = 0; i < V; i++)
      if(!done[i] && (v == -1 || d[i] < d[v]))
        v = i;
    if(v == -1)
      break;
    done[v] = 1;
    for(int i = 0; i < V; i++)
      d[i] = min(d[i], d[v] + cost[v][i][k]);
  }
}

int main()
{
loop:
  fill((int*)cost, (int*)cost + 20000, INF);
  cin >> E >> V;
  if(!E)
    return 0;

  for(int i = 0; i < E; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    cost[a][b][0] = cost[b][a][0] = c;
    cost[a][b][1] = cost[b][a][1] = d;
  }
  int k;
  cin >> k;
  for(int i = 0; i < k; i++)
  {
    int p, q, r;
    cin >> p >> q >> r;
    p--; q--;
    dj(p, r);
    cout << d[q] << endl;
  }
  goto loop;
}
