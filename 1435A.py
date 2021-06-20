def solve():
    n = int(input().strip())
    a = [int(x) for x in input().strip().split()]
    b = list(range(n))
    i = 0
    while i + 1 < n:
        b[i], b[i + 1] = -a[i + 1], a[i]
        i += 2
    print(' '.join(str(x) for x in b))


if __name__ == '__main__':
    for _ in range(int(input().strip())):
        solve()