import itertools

def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    odd = [a[i] for i in range(1, n, 2)]
    odd.sort()
    even = [a[i] for i in range(0, n, 2)]
    even.sort()
    sorted = list(itertools.chain(*zip(even, odd)))
    if n & 1:
        # because zip finishes at shortest of the 2 sequences
        sorted.append(even[-1])
    for i in range(1, n):
        if sorted[i - 1] > sorted[i]:
            return 'No'
    return 'Yes'


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())