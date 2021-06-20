import collections
import itertools
from typing import Collection

red, white = 'RW'

def invert_color(color):
    if color == red:
        return white
    return red

def gen(first_color = red):
    second_color = white if first_color == red else red
    colors = [first_color, second_color]
    while True:
        yield from colors

def reconstruct_grid(n, m, first_color):
    grid = []
    for _ in range(n):
        line = list(itertools.islice(gen(first_color=first_color), m))
        grid.append(line)
        first_color=invert_color(first_color)
    return grid

def print_grid(grid):
    for line in grid:
        print(''.join(line))

def validate(grid, reconstructed_grid):
    n, m = len(grid), len(grid[0])
    # print(f'grid size {n}:{m}')
    if reconstructed_grid is None:
        reconstructed_grid = reconstruct_grid(n, m, red)
        print('YES')
        print_grid(reconstructed_grid)
        return
    # print(f'reconstructed grid size {len(reconstructed_grid)}:{len(reconstructed_grid[0])}')
    for i in range(n):
        for j in range(m):
            if grid[i][j] not in [red, white]:
                continue
            if grid[i][j] != reconstructed_grid[i][j]:
                print('NO')
                return
    print('YES')
    print_grid(reconstructed_grid)

def solve():
    n, m = [int(x) for x in input().split()]
    grid, reconstructed_grid = [], None
    for _ in range(n):
        grid.append(list(input()))
    for line in range(n):
        non_empty = [index for index in range(m) if grid[line][index] in [red, white]]
        if len(non_empty) == 0:
            continue
        first_pos = non_empty[0]
        color = grid[line][first_pos]
        first_pos = first_pos % 2
        if first_pos & 1:
            color = invert_color(color)
        if line & 1:
            color = invert_color(color)
        reconstructed_grid = reconstruct_grid(n, m, color)
        break
    validate(grid, reconstructed_grid)


if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()