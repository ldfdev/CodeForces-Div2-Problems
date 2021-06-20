def gcd(a, b):
    if a < b:
        return gcd(b, a)
    while b > 0:
        a, b = b, a % b
    return a

def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    odd = [x for x in arr if x & 1 == 1]
    lo = len(odd)
    result = n * (n - 1) // 2 - lo * (lo - 1) // 2
    for i in range(lo):
        for j in range(i + 1, lo):
            if gcd(odd[i], odd[j]) > 1:
                result += 1
    return result

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())