def solve_for_color(color, n, k, arr):
    answer, head = 0, 0
    while head < n:
        while arr[head] == color:
            head += 1
            if head >= n:
                return answer
        answer, head = answer + 1, head + k
    return answer

def solve():
    n, k = map(int, input().split())
    house_paintings = list(map(int, input().split()))
    used_colors = set(house_paintings)

    return min(map(lambda c: solve_for_color(c, n, k, house_paintings), used_colors))


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())