def solve():
    n = int(input())
    arr = [int(x) for x in input().strip().split()]
    ops = []
    for i in range(0, n, 2):
        if arr[i] == arr[i + 1]:
            ops.extend([
                f'2 {i + 1} {i + 2}',
                f'2 {i + 1} {i + 2}',
                f'1 {i + 1} {i + 2}',
                f'1 {i + 1} {i + 2}'
            ])
            arr[i + 1] -= arr[i]
            arr[i + 1] -= arr[i]
            arr[i] += arr[i + 1]
            arr[i] += arr[i + 1]
        else:
            ops.extend([
                f'2 {i + 1} {i + 2}',
                f'2 {i + 1} {i + 2}',
                f'1 {i + 1} {i + 2}',
                f'2 {i + 1} {i + 2}',
                f'2 {i + 1} {i + 2}',
                f'1 {i + 1} {i + 2}'
            ])
            arr[i + 1] -= arr[i]
            arr[i + 1] -= arr[i]
            arr[i] += arr[i + 1]
            arr[i + 1] -= arr[i]
            arr[i + 1] -= arr[i]
            arr[i] += arr[i + 1]
    # print(arr)
    print(len(ops))
    for op in ops:
        print(op)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()