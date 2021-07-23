def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    if sum(a) != sum(b):
        print(-1)
        return
    # indices must be indexed from 1
    indices = []
    # inf_pointer: index where a[inf_pointer] < b[inf_pointer]
    inf_pointer = 0
    def update_pointer():
        nonlocal inf_pointer
        for k in range(inf_pointer, n):
            if a[k] < b[k]:
                inf_pointer = k
                return

    for i in range(n):
        if a[i] <= b[i]:
            continue
        update_pointer()
        while(a[i] > b[i]):
            a[i] -= 1
            a[inf_pointer] += 1
            indices.extend([i + 1, inf_pointer + 1])
            update_pointer()

    # print(a)
    # print(b)
    print(len(indices) // 2)
    for i in range(0, len(indices), 2):
        print(indices[i], indices[i + 1])

if __name__=='__main__':
    for _ in range(int(input())):
        solve()