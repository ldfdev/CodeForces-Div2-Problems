def solve():
    x1, y1, x2, y2 = map(int, input().strip().split())
    if x1 == x2:
        return abs(y1 - y2)
    if y1 == y2:
        return abs(x1 - x2)
    return abs(x1 - x2) + abs(y1 - y2) + 2

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())