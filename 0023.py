n = int(input())
for i in range(n):
    xa, ya, ra, xb, yb, rb = map(float, input().split())
    d = ((xa - xb)**2 + (ya - yb)**2)**0.5
    if d > ra + rb:
        print(0)
    elif ra + d < rb:
        print(-2)
    elif rb + d < ra:
        print(2)
    else:
        print(1)
