def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    m, M = min(arr), max(arr)
    min_pos = [pos + 1 for pos in range(n) if arr[pos] == m][0]
    max_pos = [pos + 1 for pos in range(n) if arr[pos] == M][0]
    if min_pos > max_pos:
        min_pos, max_pos = max_pos, min_pos
    return min(
        max_pos,
        n - min_pos + 1,
        min_pos + n - max_pos + 1
    )

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())