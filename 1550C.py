def bad_triplet(a, b, c):
    if a <= b and b <= c:
        return True
    if a >= b and b >= c:
        return True
    return False

def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    if n < 3:
        return n + n - 1
    # subarrays of lengths 1, 2, 3, 4
    good_subarrays = n + \
                     n - 1 + \
                     n - 2 + \
                     n - 3

    # checking bad subarrays of size 3
    for i in range(n - 2):
        if bad_triplet(arr[i], arr[i + 1], arr[i + 2]):
            good_subarrays -= 1

    # checking bad subarrays of size 4
    for i in range(n - 3):
        if    bad_triplet(arr[i],     arr[i + 1], arr[i + 2]) \
           or bad_triplet(arr[i],     arr[i + 1], arr[i + 3]) \
           or bad_triplet(arr[i + 1], arr[i + 2], arr[i + 3]) \
           or bad_triplet(arr[i],     arr[i + 2], arr[i + 3]):
            good_subarrays -= 1

    return good_subarrays


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())