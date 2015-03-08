N = int(input())
P = sorted([tuple(map(int, input().split())) for i in range(N)])
d = 1000000000

for i in range(len(P)):
    for j in range(i + 1, len(P)):
        p1, p2 = P[i], P[j]
        if pow(p1[0] - p2[0], 2) > d:
            break
        d = min(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), d)
print(d)
