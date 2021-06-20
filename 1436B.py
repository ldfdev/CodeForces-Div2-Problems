def solve():
    n = int(input().strip())
    prime_square = []
    for _ in range(n):
        prime_square.append(['0'] * n)
    for j in range(n // 2):
        prime_square[j][j] = '1'
        prime_square[j][n - 1 - j] = '1'
        prime_square[n - 1 - j][j] = '1'
        prime_square[n - 1 - j][n - 1 - j] = '1'
    if n & 1:
        l = n // 2
        prime_square[l][l] = '1'
        prime_square[l - 1][l] = '1'
        prime_square[l][n - 1] = '1'
    for j in range(n):
        print(' '.join(prime_square[j]))


if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()