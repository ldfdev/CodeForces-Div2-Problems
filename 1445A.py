def solve():
    n, x = [int(x) for x in input().strip().split()]
    arr = [int(x) for x in input().strip().split()]
    brr = [int(x) for x in input().strip().split()]
    try:
        _ = input()
    except EOFError:
        pass
    arr.sort()
    brr.sort(reverse=True)
    for i in range(n):
        if arr[i] + brr[i] > x:
            return "no"
    return "yes"

if __name__ == '__main__':
    for _ in range(int(input().strip())):
        print(solve())