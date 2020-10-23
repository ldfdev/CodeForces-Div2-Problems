def solve():
    n = int(input().strip())
    three, five, seven = 1 + n // 3, 1 + n // 5, 1 + n // 7
    for i in range(three):
        for j in range(five):
            for k in range(seven):
                if n == 3 * i + 5 * j + 7 * k:
                    print(i, j, k)
                    return
    print(-1)
if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()