def is_special(x):
    if len([y for y in x if y != x[0]]) > 0:
        return False
    return True

def solve():
    x = list(input().strip())
    if not is_special(x):
        return 9 * (1 + 2 + 3 + 4)
    xx = int(x[0])
    return (xx - 1) * (1 + 2 + 3 + 4) + sum(range(1, 1 + len(x)))

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())