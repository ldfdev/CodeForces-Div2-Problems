def solve():
    [a,b,c] = map(int, input().split())
    firstShop, secondShop = -1,-1
    if a < c:
        firstShop = 1
    if b * a > c:
        secondShop = b
    print(firstShop, secondShop)

if __name__=='__main__':
    for _ in range(int(input())):
        solve()