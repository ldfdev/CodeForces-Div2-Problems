def solve():
    b = list(input())
    a = [b[0]]
    for i in range(1, len(b) - 1, 2):
        if b[i] != b[i + 1]:
            raise "bad luck"
        a.append(b[i])
    a.append(b[-1])
    return ''.join(a)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())