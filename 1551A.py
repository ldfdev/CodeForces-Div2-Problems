def solve():
    n = int(input())
    c1, c2 = n // 3, n // 3
    if n % 3 == 1:
        c1 += 1
    elif n % 3 == 2:
        c2 += 1
    c1, c2 = str(c1), str(c2)
    return ' '.join((c1, c2))

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())