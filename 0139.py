for i in range(input()):
  s = raw_input()
  l = (len(s) - 4) / 2
  if l > 0 and s == ">'%s#%s~" % (('=' * l,) * 2):
    print('A')
  elif l > 0 and s == '>^%s~~' % ('Q=' * l):
    print('B')
  else:
    print('NA')
