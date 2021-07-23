import sys

def solve():
    n, strlen = [int(x) for x in input().split()]
    strings = []
    for _ in range(n):
        strings.append(input())
    for _ in range(n - 1):
        strings.append(input())
    reconstructed = []
    for i in range(strlen):
        d = set()
        for w in strings:
            w = w[i]
            if w in d:
                d.remove(w)
            else:
                d.add(w)
        assert len(d) == 1
        reconstructed.append(next(iter(d)))
    print(''.join(reconstructed))    
    sys.stdout.flush()

if __name__=='__main__':
    for _ in range(int(input())):
        solve()