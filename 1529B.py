def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    good_negatives = [x for x in a if x < 0]
    good_zeros = [x for x in a if x == 0]
    good_positves = [x for x in a if x > 0]
    if len(good_zeros) > 1:
        return len(good_zeros) + len(good_negatives)
    good_negatives.sort()
    if len(good_negatives) < 2:
        return min(1, len(good_positves)) + len(good_zeros) + len(good_negatives)
    closest_negatives = min(abs(a - b) for a, b in zip(good_negatives, good_negatives[1:]))
    take_1_positive = [x for x in good_positves if x <= closest_negatives]
    if take_1_positive:
        return 1 + len(good_zeros) + len(good_negatives)
    return len(good_zeros) + len(good_negatives)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())