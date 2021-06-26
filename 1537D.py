def solve():
    n = int(input())
    if n == 1:
        return 'Bob'
    # case n is power of 2
    if n & (n - 1) == 0:
        cnt = 0
        while n != 1:
            cnt += 1
            n = n >> 1
        if cnt & 1:
            return 'Bob'
        return 'Alice'
    # case n is odd
    if n & 1:
        return 'Bob'
    return 'Alice'
    

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())