def dfs(n, m, s):
  if n == N:
    return 1 if s == S else 0
  ans = 0
  for i in range(m, 10):
    ans += dfs(n + 1, i + 1, s + i)
  return ans;

while 1:
  N, S = map(int, raw_input().split())
  if not N:
    break
  print dfs(0, 0, 0)
