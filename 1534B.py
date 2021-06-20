
def is_peak(hist, index):
    if hist[index] <= hist[index - 1]:
        return 0
    if hist[index] <= hist[index + 1]:
        return 0
    return hist[index] - max(hist[index - 1], hist[index + 1])

def solve():
    n = int(input())
    hist_heights = [0] + [int(x) for x in input().split()] + [0]
    relative_hegihts = [0] * len(hist_heights)
    for i in range(1, n + 2):
        relative_hegihts[i] = hist_heights[i] - hist_heights[i - 1]
    ugliness = sum(abs(i) for i in relative_hegihts)
    # print(f'ugliness {ugliness}')
    for i in range(1, n + 1):
        delta_height = is_peak(hist_heights, i)
        if delta_height > 0:
            ugliness -= delta_height
        # print(f'index {i} ugliness {ugliness}')
    return ugliness
    

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())