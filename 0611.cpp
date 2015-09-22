#include<bits/stdc++.h>
using namespace std;
#define INF (1 << 30)

int N, M, C[1001], D[1001], dp[1010][1010];

int main()
{
  fill((int*)dp, (int*)dp + 1010 * 1010, INF);
  cin >> N >> M;
  for(int i = 0; i < N; i++)
    cin >> D[i];
  for(int i = 0; i < M; i++)
    cin >> C[i];
  for(int i = 0; i <= M; i++)
    dp[i][0] = 0;
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)
      dp[i + 1][j + 1] = min(dp[i][j] + C[i] * D[j], dp[i][j + 1]);
  int ans = INF;
  for(int i = 0; i <= M; i++)
    ans = min(dp[i][N], ans);
  cout << ans << endl;
}
