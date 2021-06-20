def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    arr.sort()
    if arr[0] < 0:
        print('no')
        return
    print('yes')
    b = []
    a_index = 0
    for i in range(1 + max(arr)):
        # while a_index < n and arr[a_index] == i:
        #     b.append(i)
        #     a_index += 1
        b.append(i)
    print(len(b))
    print(' '.join(str(x) for x in b))
    

if __name__=='__main__':
    for _ in range(int(input())):
        solve()