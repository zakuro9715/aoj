#include<iostream>
#include<algorithm>
#include<cstdio>
#define INF (1 << 20)
using namespace std;

int V, E, d[20][20];
int main()
{
  cin >> V >> E;
  for(int i = 0; i < 20; i++)
    for(int j = 0; j < 20; j++)
      d[i][j] = (i != j) * INF;
  for(int i = 0; i < E; i++)
  {
    int a, b, c1, c2;
    scanf("%d,%d,%d,%d", &a, &b, &c1, &c2);
    a--; b--;
    d[a][b] = c1;
    d[b][a] = c2;
  }
  int x1, x2, y1, y2;
  scanf("%d,%d,%d,%d", &x1, &x2, &y1, &y2);
  x1--; x2--;

  for(int k = 0; k < V; k++)
    for(int i = 0; i < V; i++)
      for(int j = 0; j < V; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  cout << y1 - y2 - d[x1][x2] - d[x2][x1] << endl;  
}
