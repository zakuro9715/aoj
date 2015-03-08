while 1:
    n = input();
    if not n:
        exit()
    ans = 0
    for i in range(1, n):
        m = 0
        for j in range(i, n):
            m += j
            if m > n:
                break
            if m == n:
                ans += 1
    print ans
            
