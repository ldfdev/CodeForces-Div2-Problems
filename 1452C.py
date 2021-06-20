def solve():
    string = list(input().strip())
    d = {'(' : 0,
         '[' : 0}
    ans = 0
    for s in string:
        if s in d:
            d[s] += 1
        elif s == ')':
            if d['('] > 0:
                ans += 1
                d['('] -= 1
        elif s == ']':
            if d['['] > 0:
                d['['] -= 1
                ans += 1
    return ans




if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())