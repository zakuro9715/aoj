while 1:
    h, w = map(int, raw_input().split())
    if not h and not w:
        break
    for y in range(h):
        print "#" * w
    print
