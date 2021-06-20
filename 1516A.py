def solve():
    n, k = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    for i in range(n - 1):
        if k == 0:
            break
        m = min(arr[i], k)
        arr[i] -= m
        k -= m
        arr[n - 1] += m
    return ' '.join(str(x) for x in arr)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())