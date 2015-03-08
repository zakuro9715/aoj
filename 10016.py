while 1:
    m, f, r = map(int, raw_input().split())
    if m < 0 and f < 0 and r < 0:
        break
    elif m < 0 or f < 0 or m + f < 30:
        a = "F"
    elif m + f >= 80:
        a = "A"
    elif m + f >= 65:
        a = "B"
    elif m + f >= 50 or r >= 50:
        a = "C"
    else:
        a = "D"
    print a
