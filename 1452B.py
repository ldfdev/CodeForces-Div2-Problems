def solve():
    n = int(input().strip())
    boxes = [int(x) for x in input().strip().split()]
    if n < 3:
        return 0
    big = max(boxes)
    required = (n - 1) * big - sum(boxes)
    if required < 0:
        # remains toys if each box mas big number of toys
        if abs(required) % (n - 1) != 0:
            required = n - 1 - abs(required)
    





if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())