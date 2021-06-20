
# explanation bemow:

#         1  0  0  0  0  1
# alice   1  1  0  0  0  1
# bob     1  1  0  0  1  0
# alice   1  1  0  1  1  1
# bob     1  1  1  0  1  1 (rev)
# alice   1  1  1  1  1  1
        
#         0  0  0
# alice   0  1  0
# bob     1  1  0
# alice   0  1  1 (rev)
# bob     1  1  1


def solve():
    n = int(input())
    palindrome = list(input())
    zeros = len([x for x in palindrome if x == '0'])
    if zeros == 1:
        return 'BOB'
    if zeros & 1:
        return 'ALICE'
    return 'BOB'

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())