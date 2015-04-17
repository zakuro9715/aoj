print(1 if sum([v * (5 if i % 2 else 1) * 10**(i // 2) for i, v in enumerate(list(map(int, input().split())))]) >= 1000 else 0)
