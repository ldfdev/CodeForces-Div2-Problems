def solve():
    n, a, b = [int(x) for x in input().split()]
    s = list(input())
    if b > 0:
        return n * (a + b)
    groups, prev = 0, None
    for i in s:
        if prev is None:
            groups = 1
        elif i == prev:
            continue
        else:
            groups += 1
        prev = i
    groups_of_one_color = groups // 2
    return n * a + b * (groups_of_one_color + 1)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())