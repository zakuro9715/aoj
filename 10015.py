def tonum(x):
    if x == "S":
        return 0
    if x == "H":
        return 1
    if x == "C":
        return 2
    if x == "D":
        return 3
    return int(x)
def tomark(x):
    if x == 0:
        return "S"
    if x == 1:
        return "H"
    if x == 2:
        return "C"
    if x == 3:
        return "D"
    return x

a = []
for i in range(13 * 4):
    a.append(0)
 
n = input()
for i in range(n):
    v = map(tonum, raw_input().split())
    a[v[0] * 13 + v[1] - 1] = 1
for i in range(13 * 4):
    if not a[i]:
        print "%s %d" % (tomark(i / 13), i % 13 + 1)
