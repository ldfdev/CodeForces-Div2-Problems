def solve():
    n, m, i, j = [int(x) for x in input().split()]
    if 1 == n == m:
        return [1, 1, 1, 1]
    return [1, 1, n, m]


if __name__=='__main__':
    for _ in range(int(input())):
        print(' '.join(str(x) for x in solve()))