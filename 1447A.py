

def solve():
    n = int(input().strip())
    print(n)
    print(' '.join(map(str, range(1, 1 + n))))
    
if __name__ == '__main__':
    for _ in range(int(input().strip())):
        solve()