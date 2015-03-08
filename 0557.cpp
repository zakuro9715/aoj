#include<iostream>
#include<string>
using namespace std;

long long dp[100][21];
int N, num[100];

long long dfs(int i, int v)
{
  if(dp[i][v] != -1)
    return dp[i][v];
  if(i == N - 1)
    return v == num[N - 1] ? 1 : 0;
  int plus = v + num[i];
  int minus = v - num[i];
  long long n = 0;
  if(plus >= 0 && plus <= 20)
    n += dfs(i + 1, plus);
  if(minus >= 0 && minus <= 20)
    n += dfs(i + 1, minus);
  dp[i][v] = n;
  return n;
}

int main()
{
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 21; j++)
      dp[i][j] = -1;
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> num[i];
  cout << dfs(0, 0) << endl;
}
