#include<iostream>
#include<algorithm>
using namespace std;

int N, W, d[100], v[100], mem[100][10001];

int dp(int n, int w)
{
  if(n == N)
    return 0;
  if(mem[n][w] != -1)
    return mem[n][w];
  int ans = 0;
  if(w - d[n] >= 0)
    ans = max(ans, dp(n + 1, w - d[n]) + v[n]);
  ans = max(ans, dp(n + 1, w));
  return mem[n][w] = ans;
}

int main()
{
  fill((int*)mem, (int*)mem + sizeof(mem) / sizeof(int), -1);
  cin >> N >> W;
  for(int i = 0; i < N; i++)
    cin >> v[i] >> d[i];
  cout << dp(0, W) << endl;
}
