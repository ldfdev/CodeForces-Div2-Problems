def solve():
    s = list(input().strip())
    stack = []
    for l in s:
        if l == 'A':
            stack.append(l)
        elif bool(stack):
            if stack[-1] == 'A':
                del stack[-1]
            else:
                stack.append(l)
        else:
            stack.append(l)
    i, cnt = 0, 0
    # print(stack)
    while i < len(stack) - 1:
        if stack[i] == 'B' and stack[i + 1] == 'B':
            cnt += 2
            i += 2
        else:
            i += 1
    return len(stack) - cnt

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())