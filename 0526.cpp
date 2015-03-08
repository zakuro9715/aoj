#include<iostream>
#define INF 1000000000
using namespace std;

int V, cost[100][100], K;
int main()
{
loop:
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      cost[i][j] = i == j ? 0 : INF;
  cin >> V >> K;
  if(!V)
    return 0;
  for(int i = 0; i < K; i++)
  {
    int x;
    cin >> x;
    if(x)
    {
      int c, d, e;
      cin >> c >> d >> e;
      c--; d--;
      cost[c][d] = min(cost[c][d], e);
      cost[d][c] = min(cost[d][c], e);
      for(int i = 0; i < V; i++)
      {
        for(int j = 0; j < V; j++)
        {
          cost[i][j] = min(cost[i][j], cost[i][c] + cost[c][d] + cost[d][j]);
          cost[i][j] = min(cost[i][j], cost[i][d] + cost[d][c] + cost[c][j]);
        }
      }
    }
    else
    {
      int a, b;
      cin >> a >> b;
      a--; b--;
      cout << (cost[a][b] == INF ? -1 : cost[a][b]) << endl;
    }
  }
  goto loop;
}
