while 1:
  m, n = map(int, raw_input().split())
  if not m:
    break
  p = range(m)
  t = 0
  for i in range(1, n + 1):
    s = raw_input()
    if(i % 15 == 0 and s != "FizzBuzz" or
       i % 5 == 0 and s != "Buzz" or
       i % 3 == 0 and s != "Fizz" or
       i % 3 and i % 5 and s != str(i)):
      p.pop(t)
    else:
      t = (t + 1) % len(p)
  for i in range(len(p) - 1):
    print p[i] + 1,
  print p[len(p) - 1] + 1
