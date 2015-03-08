def change(s, n):
  c = ['r', 'g', 'b']
  a, b = s[n], s[n + 1]
  if a == b:
    return s
  s = list(s)
  c.remove(a)
  c.remove(b)
  s[n], s[n + 1] = c[0], c[0]
  return ''.join(s)

while True:
  s = raw_input()
  if s == '0':
    break
  
  q = [(s, 0)]
  mem = []
  while len(q) > 0:
    v, n = q.pop(0)
    if v in mem:
      continue
    if v.count(v[0]) == len(v):
      print(n)
      break
    mem.append(v)
    for i in range(len(v) - 1):
      vv = change(v, i)
      if vv != v:
        q.append((vv, n + 1))
  else:
    print('NA')
