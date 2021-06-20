import itertools

def solve():
    [a, b] = [int(x) for x in input().strip().split()]
    mines = list(input().strip())
    cost, prev = 0, 0
    for index, (value, count) in enumerate(itertools.groupby(mines)):
        count = len(list(count))
        if index == 0:
            if value == '1':
                cost += a
            else:
                prev = count
            continue
        
        if value == '0':
            prev = count
            continue

        if index > 1:
            cost += min(a, prev * b)
        else:
            cost += a
        
    return cost

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())