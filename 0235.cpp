#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> g[100];
int N;
int dfs(int n, int from, int (*f)(int, int))
{
  int res = 0;
  for(int i = 0; i < g[n].size(); i++)
  {
    auto e = g[n][i];
    if(e.second == from || g[e.second].size() == 1)
      continue;
    res = f(res, dfs(e.second, n, f) + e.first * 2);
  }
  return res;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int add(int a, int b)
{
  return a + b; 
}

int main()
{
  while(1)
  {
    cin >> N;
    if(!N)
      break;
    for(int i = 0; i < N; i++)
      g[i].clear();
    for(int i = 0; i < N - 1; i++)
    {
      int a, b, t;
      cin >> a >> b >> t;
      a--; b--;
      g[a].push_back(make_pair(t, b));
      g[b].push_back(make_pair(t, a)); 
    }
    for(int i = 0; i < N; i++)
      sort(g[i].begin(), g[i].end());
    cout << dfs(0, -1, add) - dfs(0, -1, max) / 2 << endl;
  }
  return 0;
}
