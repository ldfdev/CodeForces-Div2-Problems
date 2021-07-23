modulus = int(1e9 + 7)

def solve():
    n, k = [int(x) for x in input().split()]
    return (n ** k) % modulus

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())