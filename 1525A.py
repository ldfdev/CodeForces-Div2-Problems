
def gcd(a, b):
    if a == 0 :
        return b
     
    return gcd(b%a, a)

def solve():
    k = int(input())
    g = gcd(100 - k, k)
    return int(100 / g)
    
if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())