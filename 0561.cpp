#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> book[10];
int mem[10][2000], N, K;

int value(int k, int n)
{
  if(n == 0)
    return 0;
  int v = 0;
  for(int i = 0; i < n; i++)
    v += book[k][i];
  return v + (n - 1) * n;
}

int dfs(int k, int n){
  if(k == 10)
    return 0;
  if(mem[k][n] != -1)
    return mem[k][n];
  int ans = 0;
  for(int i = 0; i <= book[k].size(); i++)
  {
    if(n + i > K)
      break;
    ans = max(ans, dfs(k + 1, n + i) + value(k, i));
  }
  mem[k][n] = ans;
  return ans;
}

int main()
{
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 2000; j++)
      mem[i][j] = -1;
  cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    int c, g;
    cin >> c >> g;
    book[g - 1].push_back(c);
  }
  for(int i = 0; i < 10; i++)
    sort(book[i].begin(), book[i].end(), greater<int>());
  
  cout << dfs(0, 0) << endl;
}
