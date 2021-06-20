import math

def solve():
    n = int(input())
    if n < 4:
        return n - 1
    if n & 1:
        return 3
    return 2

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())