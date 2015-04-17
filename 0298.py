v = []
for i in range(2):
    x = list(map(int, input().split()))
    N, x = x[0], x[1:]
    for j in range(N):
        v.append(x[j * 2] * 60 + x[j * 2 + 1])
print(' '.join(['{0}:{1:02d}'.format(i // 60, i % 60) for i in sorted(set(v))]))
