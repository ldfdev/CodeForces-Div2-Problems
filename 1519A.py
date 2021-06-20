def solve():
    red_beans, blue_beans, diff = (int(x) for x in input().strip().split())
    if diff == 0:
        if red_beans == blue_beans:
            return 'YES'
        return 'NO'
    if red_beans < blue_beans:
        red_beans, blue_beans = blue_beans, red_beans
    multiplier = (red_beans - blue_beans) // diff
    if (red_beans - blue_beans) % diff != 0:
        multiplier += 1
    if multiplier > blue_beans:
        return 'NO'
    return 'YES'

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())