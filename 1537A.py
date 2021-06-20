def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    s = sum(arr)
    if s == n:
        return 0
    if s < n:
        return 1
    return s - n

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())