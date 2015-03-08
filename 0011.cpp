#include<iostream>
#include<cstdio>
using namespace std;

int graph[40][40];
int ans[40];

int main()
{
  int w, n;
  cin >> w >> n;

  for(int i = 1; i <= n; i++)
  {
    int a, b;
    scanf("%d,%d", &a, &b);
    graph[a][i] = b;
    graph[b][i] = a;
  }

  for(int i = 1; i <= w; i++)
  {
    int x = i;
    for(int y = 1; y <= n; y++)
    {
      if(graph[x][y])
	x = graph[x][y];
    }
    ans[x] = i;
  }
  
  for(int i = 1; i <= w; i++)
    cout << ans[i] << endl;
  return 0;
}
