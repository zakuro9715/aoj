mass = [0] * 2000
num = [0] * 1000
while True:
  N, M = map(int, raw_input().split())
  if N == 0 and M == 0:
    break
  p = 0
  for i in range(N):
    mass[i] = input()
  for i in range(M):
    num[i] = input()

  for i in range(M):
    p += num[i];
    p += mass[p]
    if p >= N - 1:
      print i + 1
      break
