def dfs(i, v):
  if i == N - 1:
    return 1 if v == num[N - 1] else 0
  if dp[i][v] != -1L:
    return dp[i][v]
  plus = v + num[i]
  minus = v - num[i]
  n = 0L
  if plus >= 0 and plus <= 20:
    n += dfs(i + 1, plus)
  if minus >= 0 and minus <= 20:
    n += dfs(i + 1, minus)
  dp[i][v] = n
  return n

ans = 0L
N = input()
num = map(int, raw_input().split())
dp = [[-1L] * 21] * 100
print dfs(0, 0)
