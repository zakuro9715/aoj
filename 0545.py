l = []
t = []
ans = [False] * 501
while True:
  l = []
  t = []
  ans = [False] * 501
  N = input()
  M = input()
  if N == 0 and M == 0:
    break
  for i in range(M):
    a, b = map(int, raw_input().split())
    l.append([a, b])
    if a == 1:
      t.append(b)
    if b == 1:
      t.append(a)
  for i in t:
    ans[i] = True
    for j in range(M):
      if l[j][0] == i:
        ans[l[j][1]] = True
      if l[j][1] == i:
        ans[l[j][0]] = True
  res = 0
  for i in range(len(ans)):
    if ans[i] and i != 1:
      res += 1

  print res
