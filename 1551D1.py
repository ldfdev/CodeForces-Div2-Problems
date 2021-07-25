def check_from_left_top_corner(n, m):
    for i in range(1, 1 + n):
        for j in range(2, m + 1, 2):
            if (n - i) & 1:
                continue
            if (i & 1) and (j < m):
                continue
            yield [i, j]

def check(n, m, k):
    for w1, w2 in check_from_left_top_corner(n, m):
        if w1 * w2 == 2 * k:
            return 'Yes'
        if w1 < n and w2 < m:
            continue
        consumed = w1 * w2 // 2
        new_k = k - consumed
        for w1, w2 in check_from_left_top_corner(n - w1, m):
            if w1 * w2 == 2 * new_k:
                # print(f'1: {n - w1}x{m} {new_k}')
                return 'Yes'
        for w1, w2 in check_from_left_top_corner(n, m - w2):
            if w1 * w2 == 2 * new_k:
                # print(f'{n}x{m - w2} {new_k}')
                return 'Yes'
    return 'No'

def solve():
    n, m, k = [int(x) for x in input().split()]
    if k == 0:
        if n & 1:
            return 'No'
        return 'Yes'
    if check(n, m, k) == 'Yes':
        return 'Yes'
    # if check(m, n, k) == 'Yes':
    #     return 'Yes2'
    return 'No'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())