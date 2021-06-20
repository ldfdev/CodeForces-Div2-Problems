def dominant_power(n):
    return len(str(bin(n))) - 3

def solve():
    n = int(input())
    return (1 << dominant_power(n)) - 1

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())