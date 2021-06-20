def solve():
    cells, first_cell, period = map(int, input().split())
    first_cell -= 1 # 0 based index in Python
    pattern = list(map(int, input()))
    add_platform, reduce_cell = map(int, input().split())
    dp = [0] * cells
    for i in range(cells - 1, -1, -1):
        dp[i] = 1 - pattern[i]
        if i + period < cells:
            dp[i] += dp[i + period]
    lambdafun = lambda t: reduce_cell * (t - first_cell) + add_platform * dp[t]
    return min(map(lambdafun, range(first_cell, cells)))



if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())