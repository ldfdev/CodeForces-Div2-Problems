def solve():
    dishes = int(input().strip())
    couriers = [int(x) for x in input().strip().split()]
    pick_by_himself = [int(x) for x in input().strip().split()]
    l, r = 0, 2 * max(couriers)
    while l < r:
        mid, sol = (l + r) / 2, 0
        
        for i in range(dishes):
            if couriers[i] >= mid:
                sol+= pick_by_himself[i]
        if sol < mid:
            r = mid
        else:
            l = 1 + mid
    return int(l)


if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())
