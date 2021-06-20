def solve():
    n, q = [int(x) for x in input().split()]
    s = list(input())
    cnt = [[0,0]]
    for c in s:
        cnt.append([cnt[-1][0], cnt[-1][1]])
        cnt[-1][int(c)] += 1
    
    # print([x for x in cnt])

    for _ in range(q):
        L, R = [int(x) for x in input().split()]
        need0, need1 = cnt[R][0] - cnt[L - 1][0], cnt[R][1] - cnt[L - 1][1]
        if cnt[-1][int(s[R - 1])] > cnt[R][int(s[R - 1])]:
            print('yes')
            continue
        if cnt[L - 1][int(s[L - 1])] != 0:
            print('yes')
            continue
        print('no')

if __name__=='__main__':
    for _ in range(int(input())):
        solve()