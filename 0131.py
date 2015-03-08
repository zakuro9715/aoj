import sys


def rev(x, y):
  if(y > 0):
    m[y - 1][x] = not m[y - 1][x]
  if(y < 9):
    m[y + 1][x] = not m[y + 1][x]
  if(x > 0):
    m[y][x - 1] = not m[y][x - 1]
  if(x < 9):
    m[y][x + 1] = not m[y][x + 1]
  m[y][x] = not m[y][x]

def output():
  for y in range(10):
    for x in range(10):
      print ans[y][x],
    print
  sys.exit()


def dfs(y):
  if y == 10:
    output()
    for x in range(10):
      if(m[9][x] == True):
        return;
    output()
  d = []
  for i in range(10):
    if m[y - 1][i]:
      rev(i, y);
      ans[y][i] = True
      d.append(i)
  dfs(y + 1)
  for i in d:
    rev(i, y)
    dfs(1)
    ans[y][i] = False


def dd(x):
  if x == 9:
    dfs(1)
    rev(x, 0)
    ans[0][x] = True
    dfs(1)
    return 
  dd(x + 1)
  rev(x, 0)
  ans[0][x] = True
  dd(x + 1)
  ans[0][x] = False
  rev(x, 0)
  
sys.setrecursionlimit(100000)
N = input()
for n in range(N):
  ans = [[False] * 10] * 10
  m = []
  for i in range(10):
    m.append(map(bool, raw_input().split()))
  dd(0)
