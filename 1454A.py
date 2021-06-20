def solve():
    n = int(input())
    arr = list(range(2, n + 2))
    arr[-1] = 1
    print(' '.join(map(str, arr)))

if __name__=='__main__':
    for _ in range(int(input())):
        solve()