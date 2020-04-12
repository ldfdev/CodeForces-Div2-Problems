segments={
    0 : 6,
    1 : 2,
    2 : 5,
    3 : 5,
    4 : 4,
    5 : 5,
    6 : 6,
    7 : 3,
    8 : 7,
    9 : 6
}

def solve():
    n = int(input())
    if n & 1:
        if n == 1:
            pass
        n -= 3
        rem = n // segments[1]
        print('7' + str(1) * rem)
    else:
        rem = n // segments[1]
        print(str(1) * rem)

if __name__=='__main__':
    for _ in range(int(input())):
        solve()