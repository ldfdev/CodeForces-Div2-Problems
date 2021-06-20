def solve():
    x, y = [int(x) for x in input().strip().split()]
    m = min(x, y)
    M = max(x, y)
    if M == m:
        return 2 * m
    return 2 * m + 2 * (M - m - 1) + 1

    
if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())