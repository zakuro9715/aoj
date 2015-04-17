N = int(input())
n, a = -1, 0
for x in sorted([list(map(int, reversed(input().split()))) for i in range(N)], reverse=True):
    if x[0] < n:
        break
    n, a = x
print(a, n)
