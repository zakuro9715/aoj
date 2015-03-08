m = input()
for cnt in range(m):
  mem = {}
  s = raw_input()
  for i in range(1, len(s)):
    s1 = s[:i]
    s2 = s[i:]
    mem[s1 + s2] = True
    mem[s1[::-1] + s2] = True
    mem[s1 + s2[::-1]] = True
    mem[s1[::-1] + s2[::-1]] = True
    mem[s2 + s1] = True
    mem[s2 + s1[::-1]] = True
    mem[s2[::-1] + s1] = True
    mem[s2[::-1] + s1[::-1]] = True
  print len(mem)
