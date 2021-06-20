def solve():
    x = abs(int(input()))
    cnt = 0
    while (cnt * (cnt + 1) // 2) < x:
        cnt += 1
    if (cnt * (cnt + 1) // 2) == x + 1:
        return cnt + 1
    return cnt
    


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())