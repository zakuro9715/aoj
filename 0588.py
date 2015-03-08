num = 0
b = "+"
while True:
  a = input()
  if b == "+":
    num += a
  elif b == "-":
    num -= a
  elif b == "*":
    num *= a
  elif b == "/":
    num /= a
  b = raw_input()
  if b == "=":
    print num
    break
