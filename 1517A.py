def reduce_2050(n):
    k = 2050
    while k <= n:
        k = k * 10
    k = k // 10
    return n - k

def solve():
    n = int(input())
    if n % 2050 != 0:
        return -1
    minimum = 0
    while n != 0:
        minimum += 1
        n = reduce_2050(n)
    return minimum

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())