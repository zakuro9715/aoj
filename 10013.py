while 1:
    h, w = map(int, raw_input().split())
    if not h and not w:
        break
    for y in range(h):
        print "#" + ("#" if y == 0 or y == h - 1 else ".") * (w - 2) + "#"
    print
