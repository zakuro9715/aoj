class T:
    def __init__(self):
        self.min_count = 0
        self.words = {}

while True:
    data = {chr(c): T() for c in range(ord('a'), ord('z') + 1)}
    n = int(input())
    if not n:
        break
    for i in range(n):
        for s in input().split():
            d = data[s[0]]
            if s in d.words:
                d.words[s] -= 1
            else:
                d.words[s] = -1
            if d.words[s] < d.min_count:
                d.min_count = d.words[s]
    
    res = ' '.join(map(lambda v: v[1], sorted(list(map(lambda a: a[::-1], data[input()].words.items())), reverse=True)[:-6:-1]))
    print(res if res else 'NA')
    
