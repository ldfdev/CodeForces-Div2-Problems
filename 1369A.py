def solve():
    side = int(input())
    if side % 4 == 0:
        return "YES"
    return "NO"

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())