def check(n):
    p2,p3 = 0,0
    while n % 2 == 0:
        n = n >> 1
        p2 += 1
    while n % 3 == 0:
        n = n // 3
        p3 += 1
    return [n, p2, p3]

def solve():
    n = int(input())
    [one, p2, p3] = check(n)
    if one != 1:
        return -1
    if p2 > p3:
        return -1
    return p2 + 2 * (p3 - p2)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())