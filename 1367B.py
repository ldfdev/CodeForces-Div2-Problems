def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    oddeven = [0, 0]
    for i in range(n):
        if i % 2 == arr[i] % 2:
            continue
        oddeven[i % 2] += 1
    if oddeven[0] == oddeven[1]:
        return oddeven[0]
    return -1

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())