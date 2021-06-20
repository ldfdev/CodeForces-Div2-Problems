def is_sorted(arr):
    for i in range(1, len(arr)):
        if ar[i - 1] > arr[i]:
            return False
    return True

def change(arr, index, x):
    if arr[index] < x:
        return (-1, None)
    

def solve():
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    if n == 1:
        return 0
    
    if is_sorted(arr):
        return 0

    ops = 0
    # sa = sorted(arr)
    for i in range(1, n):
        if arr[i - 1] > arr[i]:
            change(arr, i - 1,x)

        if arr[i] > x:
            arr[i], x = x, arr[i]
            ops += 1
    
    return ops
        
    

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())