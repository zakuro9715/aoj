while 1:
  s = raw_input()
  if s == "-":
    break
  n = input()
  for i in range(n):
    h = input()
    s = s[h:] + s[0:h]
  print s
