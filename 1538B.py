def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    s = sum(arr)
    if s % n != 0:
        return -1
    candies = s // n # candies for each friend
    bad = [a for a in arr if a > candies]
    return len(bad)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())