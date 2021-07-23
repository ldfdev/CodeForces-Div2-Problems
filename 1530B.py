def solve():
    h, w = list(int(x) for x in input().split())
    table = []
    for _ in range(h):
        table.append(['0'] * w)
    for i in range(0, w, 2):
        table[0][i] = '1'
    i = 0
    while i < h:
        if table[i][w - 1] == '1':
            i += 2
            continue
        if table[i][w - 2] == '1':
            i += 2
            continue
        table[i][w - 1] = '1'
        i += 2
    i = w - 1
    while i >= 0:
        if table[h - 1][i] == '1':
            i -= 2
            continue
        if table[h - 2][i] == '1':
            i -= 2
            continue
        table[h - 1][i] = '1'
        i -= 2
    i = h - 1
    while i >= 2:
        if table[i][0] == '1':
            i -= 2
            continue
        if table[i][1] == '1':
            i -= 2
            continue
        table[i][0] = '1'
        i -= 2
    for line in table:
        print(''.join(line))

if __name__=='__main__':
    for _ in range(int(input())):
        solve()