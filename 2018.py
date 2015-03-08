while 1:
    n, m, p = map(int, raw_input().split())
    if not n:
        break
    x = [0] * n
    sum = 0
    for i in range(n):
        x[i] = input()
        sum += x[i]
    if not x[m - 1]:
        print 0
    else:
        print sum * (100 - p) / x[m - 1]
