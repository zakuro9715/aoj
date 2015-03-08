#include<iostream>
#include<algorithm>

using namespace std;
int wears[201][3];
int weather[201];
int mem[201][3], N, D;

int dfs(int wear, int n)
{
  if(mem[wear][n] != 0)
    return mem[wear][n];
  if(n == D - 1)
    return 0;
  int ans = 0;
  for(int i = 0; i < N; i++)
  {
    if(wears[i][0] <= weather[n + 1] && wears[i][1] >= weather[n + 1])
      ans = max(ans, dfs(i, n + 1) + abs(wears[i][2] - wears[wear][2]));
  }
  mem[wear][n] = ans;

  return ans;
}

int main()
{
  cin >> D >> N;
  for(int i = 0; i < D; i++)
    cin >> weather[i];
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < 3; j++)
      cin >> wears[i][j];
  }
  int ans = 0; 
  for(int i = 0; i < N; i++)
  {
    if(wears[i][0] <= weather[0] && wears[i][1] >= weather[0])
      ans = max(ans, dfs(i, 0));
  }
  cout << ans << endl;
}
