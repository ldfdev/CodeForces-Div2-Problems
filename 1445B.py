def solve():
    a, b, c, d = [int(x) for x in input().strip().split()]
    return max(a + b, c + d)

    
if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())