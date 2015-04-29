while True:
    N, W = map(int, input().split())
    if not N:
        break
    s = list(sorted([int(input()) for i in range(N)]))
    m = s[-1] // W + 1
    ss = [0] * m
    for c in s:
        ss[c // W] += 1
    unit = max(ss)
    a = 0
    for i, c in enumerate(ss):
        a += (1 - i / (m - 1)) * (c / unit)
    print(a + 0.01)
