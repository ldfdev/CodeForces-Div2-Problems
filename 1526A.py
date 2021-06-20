def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    b = []
    for x, y in zip(a[:n], a[n:]):
        b.extend([x, y])
    return ' '.join(str(x) for x in b)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())