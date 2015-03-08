while 1:
  day = [0] * 100
  n, q = map(int, raw_input().split())
  if not n:
    break
  for i in range(n):
    data = map(int, raw_input().split())
    for j in range(1, len(data)):
      day[data[j] - 1] += 1
  m = max(day) 
  if m >= q:
    for i in range(0, len(day)):
      if day[i] == m:
        print i + 1
        break
  else:
    print 0
