def place_in_alphabet(letter):
    return 1 + ord(letter) - ord('a')

def solve():
    
    n, q = [int(x) for x in input().split()]
    song = ['0'] + list(input())
    dp = [0] * (1 + n)
    for i in range(1, 1 + n):
        dp[i] = dp[i - 1] + place_in_alphabet(song[i])

    for _ in range(q):
        l, r = [int(x) for x in input().split()]
        print(dp[r] - dp[l - 1])

if __name__=='__main__':
    solve()