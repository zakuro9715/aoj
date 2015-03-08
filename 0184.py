while True:
    c = [0] * 7
    n = input()
    if not n:
        break
    for i in range(n):
        c[min(input() // 10, 6)] += 1
    for i in c:
        print(i)
