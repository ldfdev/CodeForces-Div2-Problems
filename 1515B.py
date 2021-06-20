from math import sqrt

def is_squared(n):
    root = int(sqrt(n))
    return n == root ** 2

def solve():
    puzzle_pieces = int(input().strip())
    if puzzle_pieces & 1:
        return 'NO'
    if is_squared(puzzle_pieces // 2):
        return 'YES'
    if puzzle_pieces % 4 == 0 and is_squared(puzzle_pieces // 4):
        return 'YES'
    return 'NO'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())