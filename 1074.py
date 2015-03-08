while True:
  n = input()
  if not n:
    break
  mem = [0] * 50
  for i in range(n):
    s = raw_input().split()
    c = s[0]
    m = int(s[1])
    for j in range(2, m + 2):
      mem[int(s[j])] += 1
  a = 1000000000
  for i in range(n):
    d = 0
    for j in range(2, m + 2):
      d += n - mem[int(s[j])] + 1
    a = min(a, d)
  print a
