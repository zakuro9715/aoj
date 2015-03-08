while True:
  mem = [-1] * 1000000
  a, l = map(int, raw_input().split())
  if not(a or l):
    break
  for i in range(100):
    s = ("%0" + str(l) + "d") % (a)
    if s in mem:
      print "%d %d %d" % (mem.index(s), int(s), i - mem.index(s))
      break
    mem[i] = s
    mx = "".join(sorted(s, reverse=True))
    mi = "".join(sorted(s))
    a = int(mx) - int(mi)

