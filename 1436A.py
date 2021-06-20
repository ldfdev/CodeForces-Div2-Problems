def solve():
    n, m = (int(x) for x in input().strip().split())
    a = (int(x) for x in input().strip().split())
    if sum(a) == m:
        return 'YES'
    return 'NO'

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())