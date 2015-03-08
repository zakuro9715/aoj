n = input()
for i in range(n):
    a = 0
    y, m, d = map(int, raw_input().split())
    a += 195 * (999 - y)
    a += (999 / 3 - y / 3) * 5
    if y % 3 :
        a += (10 - m) * 19 + (10 - m) / 2
        a += 20 - d - (m + 1) % 2 + 1
    else:
        a += (10 - m) * 20
        a += 20 - d + 1
    print a
        
