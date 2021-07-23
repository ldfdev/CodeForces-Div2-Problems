def solve():
    n = list(int(x) for x in input())
    return max(n)    

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())