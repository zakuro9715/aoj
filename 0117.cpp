#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 1000000000
using namespace std;

int d[20];
int cost[20][20];
bool done[20];

int N, M, x1, x2, y1, y2;

void dj(int s)
{
  fill(d, d + 20, INF);
  fill(done, done + 20, 0);
  d[s] = 0;
  while(1)
  {
    int v = -1;
    for(int i = 0; i < N; i++)
      if(!done[i] && (v == -1 || d[i] < d[v]))
          v = i;
    if(v == -1)
      break;
    done[v] = 1;
    for(int i = 0; i < N; i++)
      d[i] = min(d[i], d[v] + cost[v][i]);
  }
}

int main()
{
  fill((int*)cost, (int*)cost + 400, 100);
  cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int a, b, c, d;
    scanf("%d,%d,%d,%d", &a, &b, &c, &d);
    a--; b--;
    cost[a][b] = c;
    cost[b][a] = d;
  }
  scanf("%d,%d,%d,%d", &x1, &x2, &y1, &y2);
  x1--; x2--;

  int ans = y1 - y2;
  dj(x1);
  ans -= d[x2];
  dj(x2);
  ans -= d[x1];
  cout << ans << endl;
}
