import math
n = input()
ans = 0
for i in range(n):
  s = input()
  for x in range(1, int(math.ceil(math.sqrt(s)))):
    if (s - x) % (2 * x + 1) == 0:
      break
  else:
    ans += 1
print ans
