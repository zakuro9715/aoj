#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
using namespace std;

typedef pair<int, int> P;
struct Edge
{
  int cost, to, f;
  Edge(int c, int t){cost = c, to = t;}
};

int E, V, d[1000000];
vector<Edge> edge[1000000];

int main()
{
loop:
  for(int i = 0; i < 1000000; i++)
    edge[i].clear();
  for(int i = 0; i < 1000000; i++)
    d[i] = 100000000;
  cin >> V >> E;
  if(!V)
    return 0;
  for(int i = 0; i < E; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edge[a].push_back(Edge(c, b));
    edge[b].push_back(Edge(c, a));
    edge[a + V].push_back(Edge(c, b + V));
    edge[b + V].push_back(Edge(c, a + V));
  }
  for(int i = 0; i < V; i++)
    for(const auto& v1 : edge[i])
      for(const auto& v2 : edge[v1.to])
        if(v2.to != i)
          edge[i].push_back(Edge(0, v2.to + V));

  priority_queue<P, vector<P>, greater<P>> q;
  q.push(make_pair(0, 0));
  d[0] = 0;
  while(!q.empty())
  {
    auto p = q.top(); q.pop();
    int c = p.first, v = p.second;
    if(d[v] < c)
      continue;
    for(const Edge& e : edge[v])
    {
      if(d[e.to] > c + e.cost)
        q.push(make_pair(d[e.to] = c + e.cost, e.to));
    }
  }
  cout << min(d[V - 1], d[V * 2 - 1]) << endl;
  goto loop;
}
