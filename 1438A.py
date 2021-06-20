

def solve():
    n = int(input().strip())
    print(' '.join(map(str,[1] * n)))

if __name__ == '__main__':
    for _ in range(int(input().strip())):
        solve()