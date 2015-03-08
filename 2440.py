n = input()
user = [""] * n
for i in range(n):
  user[i] = raw_input()
m = input()
st = 0
for i in range(m):
  t = raw_input()
  if t in user:
    print ("Closed" if st else "Opened") + " by " + t
    st = not st
  else:
    print "Unknown " + t
