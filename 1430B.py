def solve():
    barrels, pourings = (int(x) for x in input().strip().split())
    water_amounts = [int(x) for x in input().strip().split()]
    water_amounts.sort()

    return sum(water_amounts[- pourings - 1:])

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())