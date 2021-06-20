def solve():
    n, x = [int(x) for x in input().strip().split()]
    weights = [int(x) for x in input().strip().split()]
    all_weights = sum(weights)
    if all_weights == x:
        return False, []
    swap_index, partial_sum = -1, 0
    for index, w in enumerate(weights):
        if partial_sum + w == x:
            swap_index = index
            break
        partial_sum += w
    if swap_index == -1:
        return True, weights
    sw1, sw2 = swap_index, swap_index + 1
    if sw2 == n:
        sw1, sw2 = swap_index - 1, swap_index
    tmp = weights[sw1]
    weights[sw1] = weights[sw2]
    weights[sw2] = tmp
    return True, weights

if __name__=='__main__':
    for _ in range(int(input())):
        possible, items = solve()
        if possible:
            print('YES')
            print(' '.join(str(w) for w in items))
        else:
            print('NO')