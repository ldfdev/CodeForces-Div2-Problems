def solve():
    n = int(input())
    dist = [int(x) for x in input().split()]
    dist.sort()
    cost = 0
    for i in range(1, n):
        diff = dist[i] - dist[i - 1]
        cost += diff # the only positive edge of weight = diff
        # i edges start at current node
        # n - 1 - i edges pass through current node
        # (1)---------(2)-----------(3)
        #  \                         /
        #   \_____pass through______/
        cost -= diff * i * (n - i)
        # diff appear i times from current tode to the left nodes
        # each right node (are n - i) has an edge to all nodes that i has edges to
    return cost

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())