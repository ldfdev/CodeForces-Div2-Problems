from itertools import chain, zip_longest

def solve():
    n = int(input())
    def inner():    
        if n & 1:
            yield from range(1, n - 3, 2)
            yield n
            yield n - 2
        else:
            yield from range(1, n, 2)
    i1 = range(2, n + 1, 2)
    i2 = inner()
    # print(list(i1), list(i2))
    yield from chain(*zip_longest(i1, i2))


if __name__=='__main__':
    for _ in range(int(input())):
        print(' '.join(str(x) for x in solve() if x))