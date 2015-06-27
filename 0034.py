import sys

for line in sys.stdin:
    ll = list(map(int, line.split(',')))
    s = ll[:10]
    v1, v2 = ll[10], ll[11]
    p = sum(s) / (v1 + v2) * v1

    ss = 0
    for i, l in enumerate(s):
        ss += l
        if ss >= p:
            print(i + 1)
            break
