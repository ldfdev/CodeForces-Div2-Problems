import itertools


def create_sequence(n):
    odd_numbers = itertools.count(start=1, step=2)
    even_numbers = itertools.count(start=2, step=2)
    n_sq = n ** 2
    take_while = lambda x: x <= n_sq
    yield from itertools.takewhile(take_while, odd_numbers)
    yield from itertools.takewhile(take_while, even_numbers)

def solve():
    n = int(input())
    if n == 1:
        return True, [[1]]
    if n == 2:
        return False, ''
    matrix = []
    seq = create_sequence(n)
    for _ in range(n):
        line = [next(seq) for _ in range(n)]
        # print(line)
        matrix.append(line)
    
    return True, matrix

if __name__=='__main__':
    for _ in range(int(input().strip())):
        exists, matrix = solve()
        if exists:
            for line in matrix:
                print(' '.join(str(x) for x in line))
        else:
            print(-1)