import itertools
def solve():
    n = int(input())
    s = 0
    for cnt, i in enumerate(itertools.count(start=1, step=2), start = 1):
        s += i
        if s >= n:
            return cnt

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())