while True:
  N = input()
  if not N:
    break
  A = sorted([input() for i in range(N)])
  B = [0] * N
  for i in range(1, N):
    B[i] += A[i - 1] + B[i - 1]
  print(sum(B))
