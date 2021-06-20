def solve():
    s1, s2, s3, s4 = [int(x) for x in input().split()]
    w1, w2 = max(s1, s2), max(s3, s4)
    arr = [s1, s2, s3, s4]
    arr.sort(reverse=True)
    if w1 in arr[:2] and\
       w2 in arr[:2]:
        return 'YES'
    return 'NO'

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())