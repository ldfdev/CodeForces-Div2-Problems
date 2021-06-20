def solve():
    a, b, c = sorted([int(x) for x in input().strip().split()])
    if a + b >= c:
        return 1
    return 1 + c - a - b

    
if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())