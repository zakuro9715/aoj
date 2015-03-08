INF = 10000000000
dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]
 
def dfs(x, y, m):
    if y > N :
        return 0
    if mem[x][y][m] != INF:
        return mem[x][y][m]
    n = INF
    for j in range(2 if m > 0 else 1):
        for i, s in enumerate(st[y + 1 + j]):
            srip = max(0, st[y][x][1] + s[1])
            l = abs(st[y][x][0] - s[0])
            n = min(dfs(i, y + 1 + j, m - j) + srip * l, n)
    mem[x][y][m] = n
    return mem[x][y][m]
 
while True:
    N, M = map(int, input().split())
    if N == 0:
        break
    st = [[[-INF, -INF]] for i in range(N + 3)]
    for s in st[1:-2]:
        v = list(map(int, input().split()))
        del s[0]
        for i in range(1, len(v), 2):
            s.append([v[i], v[i + 1]])
    mem = [[[INF for i in range(M + 1)] for j in range(N + 1)] for k in range(N + 4)]
    import sys
    sys.stdout.write(str((dfs(0, 0, M))) + "\n")
