#include<iostream>
#include<queue>
using namespace std;

struct Edge
{
  int to, cost;
};
bool operator<(const Edge& lht, const Edge& rht)
{
  return lht.cost > rht.cost;
}

#define MN 100

int N, M;
bool done[MN];

int main()
{
loop:
  fill(done, done + MN, false);
  vector<Edge> edges[MN];
  cin >> N >> M;
  if(!N)
    return 0;
  for(int i = 0; i < M; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  priority_queue<Edge> q;
  q.push({0, 0});
  int cost = 0;
  while(!q.empty())
  {
    auto e = q.top(); q.pop();
    if(done[e.to])
      continue;
    cost += e.cost;
    done[e.to] = true;
    for(auto ee: edges[e.to])
      q.push(ee);
  }
  cout << cost << endl;
  goto loop;
}
