from math import log

def solve():
    a, b = map(int, input().strip().split())
    required_ops = 0
    if b == 1:
        b += 1
        required_ops += 1
    req = int(log(a, b))
    if b ** req < a:
        req += 1
    return req + required_ops


if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())