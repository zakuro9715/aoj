n = input()
c = map(int, raw_input().split())
q = input()
t = map(int, raw_input().split())

mem = [False] * 501
a = 0
for i in c:
    mem[i] = True
for i in t:
    if mem[i]:
        a += 1
print a
