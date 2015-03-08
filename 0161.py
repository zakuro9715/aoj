while True:
  N = input()
  if not N:
    break
  l = []
  for i in range(N):
    c1, m1, s1, m2, s2, m3, s3, m4, s4 = map(int, raw_input().split())
    l.append(((m1 + m2 + m3 + m4) * 60 + (s1 + s2 + s3 + s4), c1))
  l = sorted(l)
  print(l[0][1])
  print(l[1][1])
  print(l[-2][1])
