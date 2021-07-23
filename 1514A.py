import math

def perfect_square(num):
    root = int(math.sqrt(num))
    return num == root**2

def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    if not all(perfect_square(x) for x in arr):
        # at least 1 number is not a perfect square
        return 'YES'
    return 'NO'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())