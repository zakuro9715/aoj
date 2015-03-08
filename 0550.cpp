#include<iostream>
using namespace std;

#define INF 1000000000

int T[10000], N, mem[10000];

int dfs(int n, int d)
{
  if(n == N)
  {
    if(N / 2 == d)
      return 0;
    return INF;
  }
  return min(
    dfs(n + 1, d + 1) + T[n],
    min(dfs(n + 1, d) + T[n],
    dfs(n + 1, d)));
}

int main()
{
  cin >> N;
  for(int i = 0; i < N - 1; i++)
    cin >> T[i];
  cout << dfs(0, 0) << endl;
}
