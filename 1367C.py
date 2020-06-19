def solve():
    occupied = '1'
    n, k = map(int, input().split())
    arr = list(input())
    marked_positions = list(filter(lambda t: arr[t] == occupied, list(range(n))))
    if not marked_positions:
        if n % (k + 1) == 0:
            return n // (k + 1)
        return (1 + n // (k + 1))
    prev = marked_positions[0]
    available = 0
    for item in marked_positions:
        if item == prev:
            continue
        available += max(0, -1 + (item - prev) // (k + 1))
        prev = item
    available += marked_positions[0] // (k + 1)
    available += (n - 1 - prev) // (k + 1)
    return available
    
if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())