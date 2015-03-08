while True:
    N = int(input())
    if not N:
        break
    e = []
    for i in range(N):
        m, a, b = map(int, input().split())
        e.append((a, m))
        e.append((b, -m))

    M = 0
    ot = 0
    for t, m in sorted(e):
        if M > 150 and ot != t:
            print('NG')
            break
        M += m
        ot = t
    else:
        print('OK')
