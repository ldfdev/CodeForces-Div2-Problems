def solve():
    arr=list(input())
    zeros,ones = 0,0
    for e in arr:
        if e == '1':
            ones += 1
        else:
            zeros += 1
    ones = min(ones, zeros)
    if ones & 1:
        return 'da'
    return 'net'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())