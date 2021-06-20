

def solve():
    n = int(input().strip())
    arr = [int(x) for x in input().strip().split()]
    incr = [0] * n
    decr = [0] * n
    decr[0] = arr[0]
    for i in range(1, n):
        decr[i] = min(arr[i] - incr[i - 1], decr[i - 1])
        incr[i] = arr[i] - decr[i]

    # print('decr',decr)
    # print('incr',incr)
    # print('arr',arr)
    for i in range(1, n):
        if incr[i] < incr[i - 1]:
            return 'NO'
        if incr[i] < 0:
            return 'NO'
    for i in range(1, n):
        if decr[i] > decr[i - 1]:
            return 'NO'
        if decr[i] < 0:
            return 'NO'
    return 'YES'
    
if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())