
def solve(n, x):
    if n < 3:
        return 1
    first_flat_on_floor = 3
    floor = 2
    while n > first_flat_on_floor + x - 1:
        first_flat_on_floor += x
        floor += 1
    return floor

if __name__=='__main__':
    for _ in range(int(input().strip())):
        n, x = map(int, input().strip().split())
        print(solve(n, x))
