while True:
  try:
    p, q = map(int, raw_input().split())
  except EOFError:
    break
  mem = {}
  a, b, c = "", p % q, 0
  while True:
    b = (b % q) * 10
    if b in mem or not b: 
      break
    mem[b] = len(a)
    a += str(b // q)
  print(a)
  if b != 0:
    print(" " * mem[b] + "^" * (len(a) - mem[b]))
