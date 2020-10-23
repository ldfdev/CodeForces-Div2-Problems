def map_int():
    return map(int, input().strip().split())

def solve():
    n, m = map_int()
    bottom_left_eq_upper_right = 0
    for _ in range(n):
        top_left, top_right = map_int()
        bottom_left, bottom_right = map_int()
        if bottom_left == top_right:
            bottom_left_eq_upper_right += 1
    if m & 1:
        return 'NO'
    if bottom_left_eq_upper_right > 0:
        return 'YES'
    return 'NO'

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())