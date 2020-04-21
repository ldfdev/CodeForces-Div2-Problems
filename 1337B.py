for _ in range(int(input())):
    x, n, m = map(int, input().split())
    if 10 * m >= x:
        print("Yes")
    else:
        while n > 0:
            n -= 1
            x = x // 2 + 10
        if 10 * m >= x:
            print("Yes")
        else:
            print("No")
