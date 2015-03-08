import math
x1, y1, x2, y2 = map(float, raw_input().split())
print math.sqrt(math.pow(x1 - x2, 2) + math.pow(y1 - y2, 2))
