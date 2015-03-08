md = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
def check(yy):
	return not (yy % 4) && (not (yy % 400) or yy % 100)
def mtd():
    pass
def std(yy, mm, dd):
	a = 0
	for y in range(2012, y):
		if y == 2012:
			a += 11
			continue
		a += sum(md)
		if check(y):
			a += 1
	if check(yy) and mm > 2:
		a += 1
	a += sum(md[:mm - 1])
	return a + dd

def dts(d):
	if d <= 10:
		return (2012, 12, 21 + d)
	
	yy = 2013
	mm = 1
	while True:
		yd = 366 if check(yy) else 365
		if d < yd:
			break
		yy += 1
		d -= yd
	for v in md:
		if d < v:
			break
		d -= v
		mm += 1
	return (yy, mm, d)
