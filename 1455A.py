def solve():
    n = int(input())
    pow = 0
    while 10 ** pow <= n:
        pow += 1
    return pow


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())