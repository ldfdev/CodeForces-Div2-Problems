def as_list():
    return list(map(int, input().split()))

def solve():
    [a, b] = as_list()
    solutions = 0
    while True:
        if a == 0 or b == 0:
            return solutions
        if a == b:
            if a == 1:
                return solutions
            if a == 2:
                return 1 + solutions
            x = a // 3
            solutions += 2 * x
            a -= 3 * x
            b -= 3 * x
        if a < b:
            [a, b] = [b, a]
        if 2 * b <= a:
            return solutions + b
        x = (a - b) // 2
        if 2 * x < a - b:
            x += 1
        solutions += x
        a -= 2 * x
        b -= x

if __name__=='__main__':
    [tests] = as_list()
    for _ in range(tests):
        print(solve())