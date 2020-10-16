for _ in range(int(input())):
    [r, g, b, w] = map(int, input().split())
    signs = []
    for x in [r, g, b, w]:
        signs.append(x & 1)
    va = len(list(filter(lambda t: t == 1, signs)))
    answer = "No"
    if (va <= 1):
        answer = "Yes"
    if (va >= 3):
        if ((r > 0) and (g > 0) and (b > 0)):
            answer = "Yes"
    print(answer)
    