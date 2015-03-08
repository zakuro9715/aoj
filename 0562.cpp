#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M, K;

struct edge
{
  int to, cost;
  edge(int t, int c)
  {
    to = t; cost = c;
  }
};

typedef pair<int, int> P;
vector<edge> edges[10000];
int d[3000];

int dijkstra(vector<int> sts)
{
  priority_queue<P, vector<P>, greater<P> > queue;
  for(auto st : sts)
  {
    d[st] = 0;
    queue.push(make_pair(0, st));
  }
  while(!queue.empty())
  {
    auto p = queue.top(); queue.pop();
    int v = p.second;
    if(d[v] < p.first)
      continue;
    for(auto e : edges[v])
    {
      if(d[e.to] > d[v] + e.cost)
      {
        d[e.to] = d[v] + e.cost;
        queue.push(make_pair(d[e.to], e.to));
      }
    }
  }
}

int main()
{
  fill(d, d + 3000, 1000000000);
  scanf("%d%d%d", &N, &M, &K);
  for(int i = 0; i < M; i++)
  {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    a--; b--;
    edges[a].push_back(edge(b, l));
    edges[b].push_back(edge(a, l));
  }

  vector<int> sts;
  for(int i = 0; i < K; i++)
  {
    int a;
    scanf("%d", &a);
    sts.push_back(--a);
  }
  dijkstra(sts);
  int ans = 0;
  for(int v = 0; v < N; v++)
    for(auto e : edges[v])
      ans = max(ans, (int)((d[v] + d[e.to] + e.cost) / 2.0 + 0.5));
  printf("%d\n", ans);
}
