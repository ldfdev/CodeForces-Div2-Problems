def solve():
    l, r = [int(x) for x in input().strip().split()]
    values = r - l
    # a // 2 + values <= a - 1
    # a + 2 * values <= 2 * a - 2
    a = 2 * (values + 1)
    if l < a // 2:
        return 'no'
    return 'yes'

if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())