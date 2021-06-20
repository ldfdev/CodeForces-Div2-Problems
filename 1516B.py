def solve():
    [n] = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    xor, s = [], 0
    for a in arr:
        s = s ^ a
        xor.append(s)
    if s == 0:
        return 'YES'
    i = 0
    while i < n:
        if xor[i] == s:
            break
        i += 1
    if 0 in xor[i + 1:]:
        return 'YES'
    return 'NO'


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())