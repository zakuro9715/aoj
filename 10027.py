n = input()
taro = 0
hanako = 0
for i in range(n):
    s = raw_input().split()
    if s[0] < s[1]:
        hanako += 3
    elif s[0] > s[1]:
        taro += 3
    else:
        hanako += 1
        taro += 1
print "%d %d" % (taro, hanako)
