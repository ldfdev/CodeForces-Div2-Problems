from collections import Counter
def solve():
    n, k = [int(x) for x in input().split()]
    a = list(input())
    b = list(input())
    chars = list(map(chr, range(97, 97 + 26)))
    # print(chars)
    da = Counter(a)
    db = Counter(b)

    reserve = 0
    for kl in chars:
        reserve += max(0, (da[kl] - db[kl])) // k
        print(f'reserve {reserve} at {kl}')
        if da[kl] + reserve * k < db[kl]:
            return 'no'
    return 'yes'
        

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())