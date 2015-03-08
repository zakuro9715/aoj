w = [list(range(i, 6)) for i in range(5)] + [[]] + [[6, 5], [7, 6, 5], [8, 9, 5], [9, 5]]
def unique(l):
    nl = []
    for x in l:
        if x not in nl:
            nl.append(x)
    return nl

n = input()
s = []
for i in range(n):
    a, b = map(int, raw_input().split())
    if a < 5 and b < 5:
        x = 1 if a < b else -1
        s = list(range(a, b + x, x))
    elif a < 5 or b < 5:
        s = w[a] + list(reversed(w[b]))
    else:
        if max(a, b) - min(a, b) < min(a, b) - max(a, b) + 5:
            x = 1 if a < b else -1
            s = list(range(a, b + x, x))
        else:
            s = w[a] + list(reversed(w[b]))
    print(' '.join(map(str, unique(s))))
