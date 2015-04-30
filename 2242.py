while True:
    N, Q = map(int, input().split())
    if not N:
        break
    a = []
    for i in range(N):
        x, y, z = input().split()
        a.append((int(z), int(z) - int(y), x))
    a = list(reversed(sorted(a)))
    for i in range(Q):
        x = int(input())
        for v in a:
            if v[0] >= x and v[1] < x:
                print(v[2], x - v[1])
                break;
        else:
            print('Unknown')
