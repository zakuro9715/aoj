import math
a, b, c = map(float, raw_input().split())
c = c / 180.0 * math.pi
h = math.sin(c) * b
l = a + b + math.sqrt(a * a + b * b - 2 * a * b * math.cos(c))
s = a * h / 2
print s
print l
print h
