def solve():
    [x,y,n] = map(int, input().split())
    k = ((n - y) // x) * x + y
    return k

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())