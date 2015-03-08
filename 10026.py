import math
while 1:
    n = input()
    if not n:
        break
    m = 0.0
    a = 0.0
    s = map(int, raw_input().split())
    for i in range(n):
        m += s[i]
    m /= n
    for i in range(n):
        a += math.pow(s[i] - m, 2)
    a = math.sqrt(a / n)
    print "%f" % a
