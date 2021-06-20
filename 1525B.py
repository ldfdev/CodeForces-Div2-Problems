def is_sorted(arr):
    n = len(arr)
    for i in range(n - 1):
        if arr[i] >= arr[i + 1]:
            return False
    return True

def solve():
    n = int(input())
    perm = [int(x) for x in input().strip().split()]
    if is_sorted(perm):
        return 0
    if perm[0] == 1 or perm[-1] == n:
        return 1
    if perm[0] == n and perm[-1] == 1:
        return 3
    return 2 
    
if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())