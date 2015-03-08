N, W = map(int, raw_input().split())
v = [0] * N
d = [0] * N
dp = [[0 for i in range(W + 1)] for j in range(N + 1)]
for i in range(N):
  v[i], d[i] = map(int, raw_input().split())
  for j in range(W + 1):
    if j < d[i]:
      dp[i + 1][j] = dp[i][j];
    else:
      dp[i + 1][j] = max(dp[i][j], dp[i][j - d[i]] + v[i])
print dp[N][W];
