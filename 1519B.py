
def solve() -> str:
    n, m, k = (int(x) for x in input().strip().split())
    dp = [[0] * m for _ in range(n)]
    for i in range(1, m):
        dp[0][i] = 1 + dp[0][i - 1]
    for i in range(1, n):
        dp[i][0] = 1 + dp[i - 1][0]
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = dp[i - 1][j] + j + 1
            assert dp[i][j] == dp[i][j - 1] + i + 1
    if k == dp[n - 1][m - 1]:
        return 'YES'
    return 'NO'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())