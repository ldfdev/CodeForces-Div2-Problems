def solve():
    n = int(input().strip())
    grid = []
    for _ in range(n):
        grid.append(input().strip())
    cells = 0
    pick1, pick2 = None , None
    zeros = len(list(filter(lambda x: x == '0', [grid[0][1], grid[1][0], grid[-1][-2], grid[-2][-1]])))
    if zeros in [0, 4]:
        cells = 2
        pick1, pick2 = (0, 1), (1, 0)
    elif zeros in [1, 3]:
        cells = 1
        target = '0'
        if zeros == 3:
            target = '1'
        if grid[1][0] == target:
            pick1 = (0, 1)
        elif grid[0][1] == target:
            pick1 = (1, 0)
        elif grid[n - 1][n - 2] == target:
            pick1 = (n - 2, n - 1)
        else:
            pick1 = (n - 1, n - 2)
    elif grid[0][1] != grid[1][0]:
        cells = 2
        pick1 = (1, 0)
        if grid[-1][-2] == grid[0][1]:
            pick2 = (n - 1, n - 2)
        else:
            pick2 = (n - 2, n - 1)

    print(cells)
    if pick1:
        pick1 = map(str, map(lambda t: t + 1, pick1))
        print(' '.join(pick1))
    if pick2:
        pick2 = map(str, map(lambda t: t + 1, pick2))
        print(' '.join(pick2))

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()