def compute(a,b,c,d):
    return (a ** b) * (c ** d)

def solve():
    k = int(input())
    [a,b,c,d] = [1,10,2,0]
    while(compute(a, b, c, d) < k):
        if b > 0:
            d += 1
            b -= 1
        else:
            a, b, c, d = c, d, c + 1, 0
        # print('After computation', [a,b,c,d])
    for l in 'codeforces':
        if b > 0:
            print(l * a, end='')
            b -= 1
        else:
            print(l * c, end='')
    return ''

if __name__=='__main__':
    print(solve())