def less(ah, ad, bh, bd):
    if ad == bd:
        return ah < bh
    return ad < bd

def check(aw, ah, bw, bh, cw, ch):
    ad, bd, cd = aw * aw + ah * ah, bw * bw + bh * bh, cw * cw + ch * ch
    return less(ah, ad, bh, bd) and less(bh, bd, ch, cd)

while True:
    h, w = map(int, input().split())
    if not w:
        break
    d = w * w + h * h
    aw, ah = 1000, 1000
    for hh in range(1, 151):
        for ww in range(hh + 1, 151):
            if check(w, h, ww, hh, aw, ah):
                aw, ah = ww, hh
    print(ah, aw)
