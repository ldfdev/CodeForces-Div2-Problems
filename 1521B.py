from collections import defaultdict

def generate_2_values(initial_value):
    while True:
        yield from [initial_value, initial_value + 1]
def solve():
    n = int(input())
    arr = [int(x) for x in input().strip().split()]
    min_value = min(arr)
    index_of_min = [i for i in range(n) if arr[i] == min_value][0]
    source = generate_2_values(min_value)
    if index_of_min & 1:
        # consume 1 value
        next(source)
    print(n - 1)
    for i in range(n):
        if i == index_of_min:
            next(source)
            continue
        print(1 + i, 1 + index_of_min, next(source), min_value)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()