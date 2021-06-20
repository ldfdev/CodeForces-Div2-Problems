def list_print(lst):
    print('.'.join(str(x) for x in lst))

def solve():
    n = int(input())
    last_pos = []
    for _ in range(n):
        last_pos.append(int(input()))
    lst = [1] * n
    index = 0
    assert last_pos[0] == 1
    list_print(lst[:index + 1])
    for i in range(1, n):
        if last_pos[i] == 1:
            index += 1
            lst[index] = 1
            list_print(lst[:index + 1])
            continue
        for last in range(index, -1, -1):
            if lst[last] + 1 == last_pos[i]:
                index = last
                lst[index] += 1
                list_print(lst[:index + 1])
                break

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()