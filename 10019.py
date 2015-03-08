while 1:
  s = raw_input()
  if s == "0":
    break
  a = 0
  for c in s:
    a += int(c)
  print a
