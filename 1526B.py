def solve():
    x = int(input())
    if x < 11:
        return 'NO'
    y = x % 11
    if y * 111 > x:
        return 'NO'
    return 'YES'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())