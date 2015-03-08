def solve():
  INF = 1000000000
  L100 = xrange(100)
  infPre = [INF] * 100
  zeroPre = [0] * 100
  while True:
    cost = [[[INF for k in range(2)] for j in L100] for i in L100]
    E, V = map(int, raw_input().split())
    VL = xrange(V)
    if not E:
      break
    for i in xrange(E):
      a, b, c, d = map(int, raw_input().split())
      a -= 1
      b -= 1
      cost[a][b][0] = cost[b][a][0] = c
      cost[a][b][1] = cost[b][a][1] = d
    k = input()
    for i in xrange(k):
      p, q, r = map(int, raw_input().split())
      p -= 1
      q -= 1
    
      d = infPre[:]
      done = zeroPre[:]
      d[p] = 0
      while True:
        v = -1
        for i in VL:
          if not done[i] and (v == -1 or d[i] < d[v]):
            v = i
        if v == q:
          print d[q]
          break
        done[v] = True
        for i in VL:
          d[i] = min(d[i], d[v] + cost[v][i][r])

solve()
