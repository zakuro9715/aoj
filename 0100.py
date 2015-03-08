while True:
  N = input()
  if not N:
    break
  m = dict()
  o = []
  for i in range(N):
    a, b, c = map(int, raw_input().split())
    o.append(a)
    m[a] = (m[a] if a in m else 0) + b * c
  oo = []
  for x in o:
    if x not in oo:
      oo.append(x)
  for i in oo:
    if m[i] >= 1000000:
      print(i)
  if max(m.values()) < 1000000:
    print('NA')
