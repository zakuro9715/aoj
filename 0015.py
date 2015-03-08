import math
n = input()
for i in range(n):
  a = input() + input()
  if(len(str(a)) > 80):
    print "overflow"
  else:
    print a
