import itertools

def solve():
    n = int(input().strip())
    piranhas = [int(x) for x in input().strip().split()]
    dominant_piranha = max(piranhas)
    dominant_indices = [x for x in range(n) if piranhas[x] == dominant_piranha]
    for dp in dominant_indices:
        if dp > 0 and piranhas[dp] > piranhas[dp - 1]:
                return dp + 1
        if dp < n - 1 and piranhas[dp] > piranhas[dp + 1]:
                return dp + 1
    return -1

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())