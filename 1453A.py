def solve():
    bottom, left = map(int, input().strip().split())
    bottom_trains = list(map(int, input().strip().split()))
    left_trains = list(map(int, input().strip().split()))
    return len([x for x in bottom_trains if x in left_trains])

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())