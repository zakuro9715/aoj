#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 1000000000

using namespace std;

int M, N;
stack<int> cups[3];

int dfs(int a, int b, int l)
{
  if(l >= M)
    return INF;
  for(int i = 0; i < 3; i++)
    if(i != 1 && cups[i].size() - 1 == N)
      return l;
  int res = INF;
  cout << l << endl;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(i == j)
        continue;
      if(abs(i - j) > 1)
        continue;
      if(cups[i].top() <= cups[j].top())
        continue;
      if(j == a && i == b)
        continue;
      cups[j].push(cups[i].top());
      cups[i].pop();
      res = min(res, dfs(i, j, l + 1));
      cups[i].push(cups[j].top());
      cups[j].pop();
    }
  }
  return res;
}

int main()
{
  while(true)
  {
    cin >> N >> M;
    if(!N)
      return 0;
    
    for(int i = 0; i < 3; i++)
    {
      int n, v;
      cin >> n;
      cups[i] = stack<int>();
      cups[i].push(0);
      for(int j = 0; j < n; j++)
      {
        cin >> v;
        cups[i].push(v);
      }
    }
    int ans = dfs(-1, -1, 0);
    cout << (ans == INF ? -1 : ans) << endl;
  }
}
