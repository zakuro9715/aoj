
dp = [[0 for j in range(4001)] for i in range(4001)]
while True:
  try:
    a = raw_input()
    b = raw_input()
    ans = 0
    for i in range(1, len(a) + 1):
      for j in range(1, len(b) + 1):
        if a[i - 1] == b[j - 1]:
          dp[i][j] = dp[i - 1][j - 1] + 1
          ans = max(ans, dp[i - 1][j - 1] + 1)
        else:
          dp[i][j] = 0
    print ans
  except EOFError:
    break
