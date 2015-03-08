while 1:
    h, w = map(int, raw_input().split())
    if not h and not w:
        break
    for y in range(h):
        if y % 2 :
            print ".#" * (w / 2) + ("." if w % 2 else "")
        else:
            print "#." * (w / 2) + ("#" if w % 2 else "")
    print
