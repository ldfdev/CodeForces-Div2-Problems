import itertools

def solve():
    n = int(input().strip())
    books = [int(x) for x in input().strip().split()]
    l = [(k, len(list(g))) for k, g in itertools.groupby(books)]
    if l[0][0] == 0:
        l = l[1:]
    if l[-1][0] == 0:
        l = l[:-1]
    return sum([x[1] for x in l if x[0] == 0])
    

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())