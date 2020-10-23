import math

def compute(n, s):
    carry = 1
    if n % s == 0:
        carry = 0
    return s - 1 + n // s - 1 + carry
def refine(n, value, iterable):
    for i in iterable:
        v = compute(n, i)
        if value >= v:
            value = min(value, v)
        else:
            break
    return value

def solve():
    n = int(input().strip())
    middle = int(math.sqrt(n))
    suboptimal = compute(n, middle)
    return min(suboptimal, refine(n, suboptimal, range(middle, 0, -1)), refine(n, suboptimal, range(middle, n)))
    

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())