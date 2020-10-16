def reducef(z1, z2):
    x = min(z1, z2)
    return (z1 - x, z2 - x)

for _ in range(int(input())):
    [x1, y1, z1] = map(int, input().split())
    [x2, y2, z2] = map(int, input().split())
    s = 0
    # 2 - 1
    if z1 > 0:
        s += 2 * min(z1, y2)
        # print('s is now', s)
        z1, y2 = reducef(z1, y2)
    if z1 > 0:
        z1, z2 = reducef(z1, z2)
    if z1 > 0:
        z1, x2 = reducef(z1, x2)
    if y1 > 0:
        y1, y2 = reducef(y1, y2)
    if y1 > 0:
        y1, x2 = reducef(y1, x2)
    if y1 > 0:
        s -= 2 * min(y1, z2)
        # print('s is now', s)
        y1, z2 = reducef(y1, z2)
    if x1 > 0:
        x1, y2 = reducef(x1, y2)
    if x1 > 0:
        x1, z2 = reducef(x1, z2)
    if x1 > 0:
        x1, x2 = reducef(x1, x2)

    if (x1 + y1 + z1 > 0):
        raise 'first tuple is not consumed'
    if (x2 + y2 + z2 > 0):
        raise 'second tuple is not consumed'
    print(s)