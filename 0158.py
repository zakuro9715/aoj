while True:
  N, c = input(), 0
  if not N:
    break
  while N > 1:
    if N % 2:
      N = N * 3 + 1
    else:
      N /= 2
    c += 1
  print(c)
