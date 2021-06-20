import itertools

def solve():
    n = int(input().strip())
    print(' '.join(map(str, list(range(2 * n, 1 + 4 * n, 2))[:n])))

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()