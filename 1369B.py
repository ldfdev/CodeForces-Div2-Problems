def solve():
    l = int(input())
    string = list(input())
    s2 = []
    first1 = -1
    for i in range(l):
        if string[i] == '0':
            s2.append('0')
        else:
            first1 = i
            break
    if first1 == -1:
        return ''.join(string)
    last0 = -1
    for i in range(first1, l):
        if string[i] == '0':
            last0 = i
    if last0 != -1:
        s2.append('0')
        for i in range(1 + last0, l):
            s2.append('1')
    else:
        for i in range(first1, l):
            s2.append('1')
    return ''.join(s2)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())