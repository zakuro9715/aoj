from fractions import Fraction
import numbers
while True:
    s = input()
    if s == '#':
        break
    if s[0] == 'w':
        f = Fraction(90)
    else:
        f = Fraction(0)
    i = 1
    while i < len(s):
        tf = Fraction(90, pow(2, i + 1))
        if s[i] == 'w':
            f += tf
            i += len('west')
        else:
            f -= tf
            i += len('north')
    print(f)
