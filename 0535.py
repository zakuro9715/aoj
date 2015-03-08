def dfs(x, y):
  if x >= M or y >= N or x < 0 or y < 0 or field[y][x] == 0:
    return 0
  field[y][x] = 0
  res = max(dfs(x + 1, y), dfs(x - 1, y), dfs(x, y - 1), dfs(x, y + 1))
  field[y][x] = 1
  return res + 1

while True:
  M = input()
  N = input()
  field = []
  if not M and not N:
    break
  for i in range(N):
    field.append(map(int, raw_input().split()))

  ans = 0
  for x in range(M):
    for y in range(N):
      ans = max(dfs(x, y), ans)
  print ans
