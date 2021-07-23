def solve():
    n = int(input())
    arr = [0] + [int(x) for x in input().split()]
    pairs = 0
    for i in range(1, 1 + n):
        multiple = arr[i]
        while multiple <= 2 * n:
            j = multiple - i
            if j >= 1 and j <= n and j != i:
                if arr[i] * arr[j] == i + j:
                    pairs += 1
            multiple += arr[i]
    assert pairs % 2 == 0
    return pairs // 2


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())