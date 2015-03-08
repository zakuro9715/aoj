INF = 10000000000
sl = [60,  80,  100,  120,  140,  160,  INF]
wl = [2,   5,   10,   15,   20,   25,   INF]
pl = [600, 800, 1000, 1200, 1400, 1600, 0  ]

def le(n, l):
  for i, v in enumerate(l):
    if v >= n:
      return i

while True:
  N = input()
  if not N:
    break
  s = 0
  for i in range(N):
    x, y, h, w = map(int, raw_input().split())
    s += pl[max(le(x + y + h, sl), le(w, wl))]
  print(s)
