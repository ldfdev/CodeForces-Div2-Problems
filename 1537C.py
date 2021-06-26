def solve():
    n = int(input())
    heights = [int(x) for x in input().split()]
    heights.sort()
    if n == 2:
        yield from heights
        return
    min_pair_index = 0
    for i in range(n - 1):
        if heights[i + 1] - heights[i] < heights[min_pair_index + 1] - heights[min_pair_index]:
            min_pair_index = i
    yield from heights[min_pair_index + 1:]
    yield from heights[:min_pair_index + 1]

if __name__=='__main__':
    for _ in range(int(input())):
        print(' '.join(str(x) for x in solve()))