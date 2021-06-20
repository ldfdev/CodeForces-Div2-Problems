
def solve():
    n, m, r, c = map(int, input().split())
    costs = [
        abs(r - 1) + abs(c - 1),
        abs(r - 1) + abs(c - m),
        abs(r - n) + abs(c - 1),
        abs(r - n) + abs(c - m)
    ]
    return max(costs)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())