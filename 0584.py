import itertools

n = int(input())
A = sorted([int(input()) for i in range(n)])[:4]

B = []
for a, b in itertools.permutations(A, 2):
    B.append(a * pow(10, len(str(b))) + b)

print(sorted(B)[2])
