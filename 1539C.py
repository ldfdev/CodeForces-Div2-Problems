import heapq

def solve():    
    n, k, x = [int(x) for x in input().split()]
    levels = [int(x) for x in input().split()]
    levels.sort()
    # print(levels)
    heap = []
    splitting_parts = 0
    for i in range(1, n):
        diff = levels[i] - levels[i - 1]
        if diff <= x:
            continue
        needed = diff // x
        if needed > 1 and diff % x == 0:
            needed -= 1
            # if the difference is A * x
            # we need only A - 1 additions because each is at distance of A from previous
            #  and the last at distance A from the next (i.e. levels[i])
        heapq.heappush(heap, needed) # are necessary diff // x elements to merge i into the previous block
        splitting_parts += 1
        # print(f'Elements {levels[i]} and {levels[i - 1]} are unstable {diff} {x}')
    try:
        while k > 0:
            cheapest = heapq.heappop(heap)
            # print(f'cheapest {cheapest}')
            k -= cheapest
            if k >= 0:
                splitting_parts -= 1
    except IndexError:
        # when heap is emptied
        pass
    return splitting_parts + 1

if __name__=='__main__':
    print(solve())