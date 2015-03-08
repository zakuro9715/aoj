while True:
  N = input()
  if not N:
    break
  a, b = -1, 100000000
  for j in range(N):
    i, h, w = map(int, raw_input().split())
    h /= 100.00
    bmi = w / (h * h)
    if abs(bmi - 22) < b:
      b = abs(bmi - 22)
      a = i
  print(a) 
