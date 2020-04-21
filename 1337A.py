for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    x, y, z = a, b, c
    if x + y <= z:
        if b < c:
            y = c
        else:
            x = b
    print(x, y, z)
