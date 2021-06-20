alive, dead = 1, 0

def solve():
    n, m = [int(x) for x in input().split()]
    arr  = [int(x) for x in input().strip()]
    b = [0] * n
    alive_elements = [i for i in range(n) if arr[i] == alive]
    for i in range(len(alive_elements)):
        if i == 0:
            # all elements up to first alive
            b[max(alive_elements[i] - m, 0)] += 1
            b[alive_elements[i]] -= 1
        if i == len(alive_elements) - 1:
            # all elements fro  last active to end
            if alive_elements[i] < n - 1:
                b[alive_elements[i] + 1] += 1
            if alive_elements[i] + m < n - 1:
                b[alive_elements[i] + m + 1] -= 1
            continue
        # al elements between alive_elements[i] and the next alive element
        dead_elements = alive_elements[i + 1] - alive_elements[i] - 1
        dead_elements = min(m, dead_elements // 2)
        # print(f'between {alive_elements[i]} and {alive_elements[i + 1]} are {dead_elements} dead')
        b[alive_elements[i] + 1] += 1
        b[alive_elements[i] + 1 + dead_elements] -= 1
        b[alive_elements[i + 1]] -= 1
        b[alive_elements[i + 1] - dead_elements] += 1

    carry = 0
    for i in range(n):
        carry += b[i]
        if carry > 0:
            b[i] = alive
        if arr[i] == alive:
            b[i] = alive
        if b[i] not in [dead, alive]:
            b[i] = dead

    return ''.join(str(x) for x in b)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())