if __name__=='__main__':
    tests = int(input())
    for _ in range(tests):
        [a, b] = list(map(int, input().split()))
        m = a
        if   (a >= b):
            m = max(a, 2 * b)
        else:
            m = max (2 * a, b)
        print(m**2)
