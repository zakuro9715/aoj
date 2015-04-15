#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int> P;

int N, M;
vector<P> g[100];
bool done[100];
int main()
{
  while(true)
  {
    fill(done, done + 100, 0);
    for(int i = 0; i < 100; i++)
      g[i].clear();
    
    cin >> N;
    if(!N)
      break;
    cin >> M;

    for(int i = 0; i < M; i++)
    {
      int a, b, c;
      scanf("%d,%d,%d", &a, &b, &c);
      printf("%d %d %d \n", a, b, c);
      c = c / 100 - 1;
      g[a].push_back(make_pair(c, b));
      g[b].push_back(make_pair(c, a));
    }

    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(0, 0));
    int cost = 0;
    while(q.size())
    {
      auto p = q.top(); q.pop();
      if(done[p.second])
        continue;
      done[p.second] = true;
      cost += p.first;
      for(auto e: g[p.second])
      {
        if(done[e.second])
          continue;
        q.push(e);
      }
    }
    cout << cost << endl;
  }
}
