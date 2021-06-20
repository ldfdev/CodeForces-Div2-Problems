
def solve():
    n = int(input())
    chosen_numbers = list(map(int, input().split()))
    d = dict()
    for (index, c) in enumerate(chosen_numbers):
        if c in d:
            d[c].append(1 + index)
        else:
            d[c] = [1 + index]
    keys = list(d.keys())
    keys.sort()
    for k in keys:
        if len(d[k]) == 1:
            return d[k][0]
    return -1

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())