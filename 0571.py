JOI = "JOI"
t = 0
ans = 0
n = [0, 0, 0]
s = raw_input()
for i, c in enumerate(s):
  if c == JOI[t]:
    n[t] += 1
  elif t == 2:
    if n[0] >= n[1] <= n[2]:
      ans = max(ans, n[1])
    t = 0
    n = [0, 0, 0]
    if c == JOI[t]:
      n[t] += 1
  elif c == JOI[t + 1]:
    t += 1
    n[t] += 1
  else:
    t = 0
    n = [0, 0, 0]
if n[0] >= n[1] <= n[2]:
  ans = max(ans, n[1])
print ans
