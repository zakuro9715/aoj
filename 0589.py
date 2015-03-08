def getkey(a):
  return "%6s" % a

n = input()
dic = {}
for i in range(n):
  a, b = raw_input().split()
  b = int(b)
  if a in dic:
    dic[a] += b
  else:
    dic[a] = b
for a in sorted(dic, key=getkey):
  print "%s %d" % (a, dic[a])
