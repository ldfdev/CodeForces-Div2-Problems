def solve():
    _ = input()
    arr = sorted([int(x) for x in input().strip().split()])
    if sum(arr) == 0:
        print('NO')
    else:
        print('YES')
        final, b = [], []
        sp = 0
        for a in arr:
            if sp + a == 0:
                final.append(a)
            else:
                b.append(a)
                sp += a
        b = b + final
        sp = 0
        for a in b:
            sp += a
            if sp == 0:
                b.reverse()
                break
        print(' '.join(str(x) for x in b))


if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()