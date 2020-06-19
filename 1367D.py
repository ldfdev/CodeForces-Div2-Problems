def solve():
    s = list(input())
    m = int(input())
    b = list(map(int, input().split()))
    t = ['-'] * m
    letter_count = dict()
    for l in s:
        if l in letter_count:
            letter_count[l] += 1
        else:
            letter_count[l] = 1
    used_letters, maximal_position = 0, 0
    maximal_letters = sorted(list(set(s)), reverse=True)
    while(used_letters < m):
        used_positions = list(filter(lambda x: b[x] == 0, list(range(m))))
        while(letter_count[maximal_letters[maximal_position]] < len(used_positions)):
            maximal_position += 1
        used_letters += len(used_positions)
        for i in range(m):
            if i in used_positions:
                b[i] = -1
                t[i] = maximal_letters[maximal_position]
            if b[i] == -1:
                continue
            for j in used_positions:
                b[i] -= abs(i - j)
        maximal_position += 1
        
        # print('After {x} iterations'.format(x = maximal_position), b)
    return ''.join(t)


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())