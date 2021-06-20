def solve():
    n, q, k = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    possibilities = [0] * (1 + n)
    for i in range(n):
        if i == 0:
            possib = arr[i + 1] - 2
        elif i == n - 1:
            possib = k - arr[i - 1] - 1
        else:
            possib = arr[i + 1] - arr[i - 1] - 2
        print(f'There are {possib} for changing arr[{i + 1}]={arr[i]}')
        possibilities[i + 1] = possib
        if i > 0:
            possibilities[i + 1] += possibilities[i]
        

    for _ in range(q):
        l, r = map(int, input().strip().split())
        r, l = r - 1, l - 1
        if r == l:
            print(k - 1); continue
        
        print(arr[r] - 2 + k - arr[l] - 1 +\
              possibilities[r - 1] - possibilities[l])

if __name__=='__main__':
    solve()