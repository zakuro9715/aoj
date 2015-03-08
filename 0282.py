INF = 2000000000

class seg():
  a = INF
  b = INF
  def __init__(self, a, b):
    self.a = a
    self.b = b

def seg_min(a, b):
  if(a.a == b.a):
    return b if b.b < a.b else a
  else:
    return b if b.a < a.a else a

def update(i, x):
  i += n - 1
  dat[i] = x
  while(i > 0):
    i = (i - 1) / 2
    dat[i] = seg_min(dat[i * 2 + 1], dat[i * 2 + 2])

def query(a, b, k, l, r):
  if a >= r or b <= l:
    return seg(INF, INF)
  if a <= l and b >= r:
    return dat[k]
  vl = query(a, b, k, l, (l + r) / 2)
  vr = query(a, b, k, (l + r) / 2, r)
  return seg_min(vl, vr)

dat = [seg(INF, INF)] * (1 << 18 + 1)
ans = [0] * (1 << 17)
print len(ans)
print len(dat)

N, R, L = map(int, raw_input().split())
n = 1
while(n < N):
  n *= 2
n *= 2
for i in range(n * 2 - 1):
  dat[i] = seg(INF, INF)
for i in range(N):
  update(i, seg(0, i))

t_old = 0
for i in range(R):
  d, t, x = map(int, raw_input().split())
  d -= 1
  for j in range(n):
    print dat[j].a,
  ans[query(0, N, 0, 0, n).b] += t - t_old
  s = dat[d + n - 1]
  update(d, seg(s.a + x, s.b))

ans[query(0, N, 0, 0, n)] += L - old_t

m = 0
for i in range(N):
  m = max(m, ans[i])
for i in range(N):
  if m == ans[i]:
    print i + 1
    break

