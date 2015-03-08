while 1:
    n, x = map(int, raw_input().split())
    if not n and not x:
        break
    a = 0
    n += 1
    for i in range(1, n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                if i + j + k == x:
                    a += 1
    print a
