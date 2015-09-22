N = int(input())
M = int(input())
A = list(map(int, input().split()))
p = [0] * N
for i in range(M):
    for bi, b in enumerate(map(int, input().split())):
        if b == A[i]:
            p[bi] += 1
        else:
            p[A[i] - 1] += 1
print('\n'.join(map(str, p)))
