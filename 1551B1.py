import itertools
from collections import Counter, defaultdict

def structure(arr):
    d = defaultdict(list)
    for i in range(len(arr)):
        d[arr[i]].append(i)
    return d

def color_arr(arr, max_colors):
    n = len(arr)
    d = structure(arr)
    colored = [0] * n
    all_ = 0
    for k in d.keys():
        bound = min(max_colors, len(d[k]))
        d[k] = d[k][:bound]
        assert len(d[k]) <= max_colors
        all_ += len(d[k])
    all_ = (all_ // max_colors) * max_colors
    color_range = itertools.cycle(range(1, 1 + max_colors))
    for i in \
        itertools.islice(
            itertools.chain(*d.values()),
            all_):
        colored[i] = next(color_range)        
    return colored


def index_of_sorted(sorted_, start, cnt):
    for j in range(start, len(sorted_)):
        if sorted_[j] > cnt:
            return j
    return len(sorted_)


def solve():
    arr  = list(input())
    n, k = len(arr), 2 # k = 2 colors
    d = structure(arr)
    sorted_ = [len(x) for x in d.values()]
    sorted_.sort()
    max_colors = k
    N = len(sorted_)
    index = index_of_sorted(sorted_, 0, k)
    le_index = sum(sorted_[:index])
    how_many = (le_index // max_colors) * max_colors + max_colors * (N - index)
    # no need to try coloring with 1 color, 2 colors ..
    # it is mandatory to use all k colors available  

    # for c in range(2, k + 1):
    #     new_index = index_of_sorted(sorted_, index, c)
    #     le_index += sum(sorted_[index:new_index])
    #     index = new_index
    #     c_colored = (le_index // c) * c + c * (N - index)
    #     if how_many < c_colored:
    #         how_many = c_colored
    #         max_colors = c

    # k = 2 then colors are 1 and 2
    #roblem asks how many items are painted red given thar red/green are the colors used
    return len([x for x in color_arr(arr, max_colors) if x == 1])


if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())