def solve():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    carry, ops = 0, 0
    for i in range(1, n - 1):
        if arr[i] + carry == arr[i - 1]:
            continue
        carry += (arr[i - 1] - arr[i])
    
    return carry


if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())