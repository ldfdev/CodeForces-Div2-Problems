def solve():
    a, b = [int(x) for x in input().strip().split()]
    common = a & b
    return  (a ^ common) + (b ^ common)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())