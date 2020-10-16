for _ in range(int(input())):
    [n,k] = map(int, input().split())
    if k >= n:
        print(k - n)
    elif (n - k) % 2 == 0:
        print(0)
    else:
        print(1)