def count_tokens(grid):
    solver = lambda t: len(list(filter(lambda x: x if x in 'XO')))
    return sum(map(solver, grid))

def solve():
    n = int(input())
    grid = []
    for _ in range(n):
        grid.append(input().split())
    tokens = count_tokens(grid) // 3
    



if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())