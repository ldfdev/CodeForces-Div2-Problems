def solve_1003B(a, b, x):
    s = []
    x = x + 1

    if a > b:
        bit = 0
    else:
        bit = 1

    def changeBit(bit):
        # print('Bit value is {}'.format((bit + 1)%2))
        return (bit + 1)%2

    while x > 2:
        x = x - 1
        s = s + [str(bit)]
        if bit == 1:
            b = b - 1
        else:
            a = a - 1
        bit = changeBit(bit)

    while x > 0:
        x = x - 1
        if bit == 1:
            s = s + [str(bit)] * b
            bit = changeBit(bit)
        else:
            s = s + [str(bit)] * a
            bit = changeBit(bit)
    return s

if __name__=='__main__':
    [a,b,x] = [int(a) for a in input().split(' ')]
    s = solve_1003B(a, b, x)
    print(''.join(s))