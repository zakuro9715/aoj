import sys
mem = [0] * 26
for s in sys.stdin:
  for c in s.upper():
    if(c < 'A' or c > 'Z'):
      continue
    mem[ord(c) - ord('A')] += 1
for i in range(26):
  print chr(i + ord('a')) + " : %d" % mem[i]
