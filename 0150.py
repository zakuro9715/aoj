MN = 10000
tp = []
op = -5
mem = [False * 2] + [True] * MN
for i in range(2, MN):
  if not mem[i]:
    continue
  if i - op == 2:
    tp.append((op, i))
  op = i
  for j in range(i + i, MN, i):
    mem[j] = False
tp.append((MN + 1, MN + 1))
while True:
  N = input()
  if not N:
    break
  for i, p in enumerate(tp):
    if p[1] > N:
      print('%d %d' % (tp[i - 1][0], tp[i - 1][1]))
      break
