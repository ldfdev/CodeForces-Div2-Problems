def as_list():
    return list(map(int, input().split()))

def give_range(old_range, new_range):
    [old_l, old_r] = old_range
    [l, r] = new_range
    if old_r < l or r < old_l:
        return [old_l, old_r]
    return [min(old_l, l), max(old_r, r)]

def solve():
    [n, x, m] = as_list()
    ones = [x, x]
    ops = []
    for _ in range(m):
        ops.append(as_list())
        ones = give_range(ones, ops[-1])
    [l, r] = ones
    return (r - l + 1)

if __name__=='__main__':
    [tests] = as_list()
    for _ in range(tests):
        print(solve())