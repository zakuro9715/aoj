MN = 1000000
prime = []
mem = [False] * 2 + [True] * MN
for i in range(2, MN):
  if not mem[i]:
    continue
  prime.append(i)
  for j in range(i + i, MN, i):
    mem[j] = False

while True:
  N, ans = input(), 0
  if not N:
    break

  for p in prime:
    if p > N / 2:
      break
    if mem[N - p]:
      ans += 1
  print(ans)
