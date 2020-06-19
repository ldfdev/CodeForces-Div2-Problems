def solve():
    [a, b, n] = map(int, input().split())
    if a > b:
        a, b = b, a
    ops = 0
    while( b <= n):
        a, b = b, a + b
        ops += 1
        # print(ops, num2)
    return ops

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())