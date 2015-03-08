coins = [10, 50, 100, 500]
def s(value):
    a = list(map(int, input().split()))
    pay = [0, 0, 0, 0]
    ms = sum([a[i] * coins[i] for i in range(4)]) - value
    m = [ms % 50 // 10, ms % 100 // 50, ms % 500 // 100, ms // 500]
    for cc, aa, mm in zip(coins, a, m):
        if aa > mm:
            print(cc, aa - mm)

s(int(input()))
while True:
    value = int(input())
    if not value:
        break
    print()
    s(value)
