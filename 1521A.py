def solve():
    a, b = map(int, input().strip().split())
    if b == 1:
        print('no')
        return
    
    p1, p2 = 999931, 999983 # primes different than a and b
    if p1 in [a, b]:
        p1 = 150659
    if p2 in [a, b]:
        p2 = 100153
    # let p1, p2 big primes
    # a * b * p1 + a * p2 = a * (b * p1 + p2)
    # \----x---/   \-y--/   \------z--------/  
    x, y, z = a * b * p1, a * p2, a * (b * p1 + p2)
    print('yes')
    print(x, y, z)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()