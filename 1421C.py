def is_palindrome(s):
    stack_pos = -1
    for i in range(len(s)):
        if stack_pos == -1:
            stack_pos = i
        elif s[i] == s[stack_pos]:
            stack_pos -= 1
        else:
            stack_pos += 1
    return stack_pos == -1

def solve():
    s = list(input().strip())
    if is_palindrome(s):
        print(0)
        return
    

if __name__=='__main__':
    solve()