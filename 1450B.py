def solve():
    n, k = map(int, input().strip())
    xy = []
    for _ in range(n):
        x, y = map(int, input().split())
        xy.append((x, y))
    for center_point in xy:
        # consider each point as the center
        



if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())