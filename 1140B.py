


if __name__=='__main__':
    tests = int(input())
    for _ in range(tests):
        n = int(input())
        s = list(input())
        # check from left
        right_encountered = -1
        cost_from_left = 0
        for i in range(n):
            if s[i] == '<':
                if right_encountered == 1:
                    continue
                cost_from_left += 1
            else:
                right_encountered = 1
        # print('cost from left', cost_from_left)
        left_encountered = -1
        cost_from_right = 0
        for i in range(n - 1, -1, -1):
            if s[i] == '>':
                if left_encountered == 1:
                    continue
                cost_from_right += 1
            else:
                left_encountered = 1
        # print('cost from right', cost_from_right)
        print(min(cost_from_left, cost_from_right))
        