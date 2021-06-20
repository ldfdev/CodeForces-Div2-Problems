def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    return gcd(a % b, b) 

def get_min_divisor(q):
    for i in range(2, q):
        if q % i == 0:
            return i
    return q

def get_min_divisor_with_reduce(q):
    min_div = -1
    for i in range(2, q):
        if i > q:
            break
        ans = 1
        while q % i == 0:
            ans *= i
            q = q // i
        if ans == 1:
            continue
        if min_div == -1:
            min_div = ans
        min_div = min(min_div, ans)

    return min_div

def solve():
    p, q = [int(x) for x in input().strip().split()]
    if p % q == 0:
        print('branch1')
        x = p // q
        gcdxq = gcd(x, q)
        if gcdxq == 1:
            print('branch1 1')
            return (q // get_min_divisor(q)) * x
        if gcdxq == x:
            return q // get_min_divisor_with_reduce(q)
        else:
            print('branch 1 2')
            print(f'min div of {q} is {get_min_divisor(q)}')
            return (q // get_min_divisor(q)) * (x // gcdxq)
    if q % p == 0:
        return 1
    return p
    
    
if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())