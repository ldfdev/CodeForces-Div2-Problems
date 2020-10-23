def solve():
    n = int(input().strip())
    print(2)
    if n == 2:
        print(1, 2)
        return
    l = list(range(1, 1 + n))
    initial = False
    while len(l) > 1:
        # print(l)
        if initial == False:
            initial = True
            print(l[-1], l[-3])
            x = (l[-1] + l[-3]) // 2
            del l[-1]
            del l[-2]
            l.append(x)
        elif l[-1] == l[-2]:
            print(l[-2], l[-1])
            del l[-1]
        else:
            print(l[-1], l[-2])
            x = (l[-1] + l[-2]) // 2
            del l[-1]
            del l[-1]
            l.append(x)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()