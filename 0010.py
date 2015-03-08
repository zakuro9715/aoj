import math
n = input()
for i in range(n):
  x1, y1, x2, y2, x3, y3 = map(float, raw_input().split())
  d1 = x1 * x1 + y1 * y1;
  d2 = x2 * x2 + y2 * y2;
  d3 = x3 * x3 + y3 * y3;
  u = 0.5 / ( x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3)
  xp = u* (d1 * y2 - d2 * y1 + d2 * y3 - d3 * y2 + d3 * y1 - d1 * y3)
  yp = u * (x1 * d2 - x2 * d1 + x2 * d3 - x3 * d2 + x3 * d1 - x1 * d3)
  r = math.sqrt((xp - x1) * (xp - x1) + (yp - y1) * (yp - y1))
  print "%.3f %.3f %.3f" % (xp, yp, r)
