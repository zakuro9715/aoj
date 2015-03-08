eps = 0.00000001
while True:
    x, y, s = map(int, raw_input().split())
    if x == 0:
        break
    x /= 100.0
    y /= 100.0
    n = 0
    for a in range(1, s):
        for b in range(1, s):
            if (int)(a * (1 + x) + eps) + (int)(b * (1 + x) + eps) == s:
                n = max(n, (int)(a * (1 + y) + eps) + (int)(b * (1 + y) + eps))
    print(n)
