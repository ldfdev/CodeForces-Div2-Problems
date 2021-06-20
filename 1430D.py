def solve():
    n = int(input().strip())
    s = list(input().strip())
    cnt, start, stop = 0, 0, n - 1
    if n == 1:
        return 1
    while start <= stop:
        cnt += 1
        if start == n - 1:
            break
        if s[start] != s[start + 1]:
            # choose at step 1 the last element
            stop -= 1
        else:
            # choose at step 1 the first element
            start += 1
        if start == n - 1:
            break
        while s[start] == s[start + 1]:
            start += 1
            if start > stop:
                break
            if start + 1 >= n:
                break
        start += 1
    return cnt

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())