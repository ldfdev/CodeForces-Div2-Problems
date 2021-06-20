

def solve():
    n, m = (int(x) for x in input().strip().split())
    less = 0
    minimum = None
    X = 0
    for _ in range(n):
        new_list = [int(x) for x in input().strip().split()]
        new_list_gz = list(filter(lambda t: t > 0, new_list))
        new_list_lz = list(map(abs, filter(lambda t: t <= 0, new_list)))
        m = None
        if bool(new_list_gz):
            m = min(new_list_gz)
        if m is None:
            m = min(new_list_lz)
        if bool(new_list_lz):
            m = min(m, min(new_list_lz))
        if minimum is None:
            minimum = m
        minimum = min(minimum, m)
        X += sum(new_list_gz) + sum(new_list_lz)
        less += len(new_list_lz)
    if less & 1:
        X -= 2 * minimum
    return X

if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())