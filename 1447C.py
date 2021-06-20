
class Weight:
    def __init__(self, w, i):
        self.weight = w
        self.index =i
    def __lt__(self, other):
        return self.weight < other.weight
         
def solve():
    n, total = (int(x) for x in input().strip().split())
    arr = list(map(lambda x: Weight(x[0], x[1]), zip([int(x) for x in input().strip().split()], range(1, 1 + n))))
    lim = total // 2
    if total & 1:
        lim += 1
    arr_gt_eq_lim = list(filter(lambda t: t.weight >= lim and t.weight <= total, arr))
    arr_lt_lim = list(filter(lambda t: t.weight < lim, arr))
    if len(arr_gt_eq_lim) > 0:
        print(1)
        print(arr_gt_eq_lim[0].index)
        return
    index, s = 0, 0
    while index < len(arr_lt_lim):
        s += arr_lt_lim[index].weight
        if s >= lim:
            break
        index += 1
    if index == len(arr_lt_lim):
        print(-1)
    else:
        print(1 + index)
        print(' '.join(map(str, map(lambda t: t.index, arr_lt_lim[:1 + index]))))
    

if __name__ == '__main__':
    for _ in range(int(input().strip())):
        solve()