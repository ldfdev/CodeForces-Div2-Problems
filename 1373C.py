def solve():
    arr=list(input())
    cnt = 0
    cntValues = []
    for (idx, e) in enumerate(arr):
        if e == '+':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            cntValues.append(1 + idx)
            cnt += 1

    ans = len(arr)
    if bool(cntValues):
        ans += sum(cntValues)
    return ans 
    

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())