def solve():
    [hi, lo, barrel] = map(int, input().split())
    if 2 * barrel <= hi + lo:
        return 2
    items = (hi - barrel) // (2 * barrel - hi - lo)
    temp = lambda t: (((t + 1) * hi + t * lo) - (2 * t + 1) * barrel) / (2 * t + 1)
    if abs(temp(items)) > abs(temp(items + 1)):
        items += 1
    return 2 * items + 1
 
if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())