import enum

class Bound(enum.Enum):
    LOWER = enum.auto()
    UPPER = enum.auto()

not_found = -1

def bin_search(arr, from_, to_, what_, bound):
    if from_ < 0:
        return -1
    if len(arr) <= to_:
        return -1
    middle = from_ + to_ // 2
    if what_ == arr[middle]:
        return arr[middle]
    # if middle is too big
    if arr[middle] > what_:
        if middle - 1 < from_:
            # might be bigger that LOWER bound what
            if bound == Bound.LOWER:
                return middle
            return -1
            # return middle
        if arr[middle - 1] <= what_:
            return middle - 1
        return bin_search(arr, from_, middle - 1, what_, bound)
    # if middle is too small
    if middle + 1 > to_:
        # if bound == Bound.LOWER:
            return -1
        # return middle
    if arr[middle + 1] > what_:
        if bound == Bound.UPPER:
            return middle + 1
        
    return bin_search(arr, middle + 1, to_, what_, bound)
        

def solve():
    n, l, r = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    arr.sort()
    print(arr)
    index_pairs = 0
    for i in range(n - 1):
        lower = bin_search(arr, i + 1, n - 1, l - arr[i], Bound.LOWER)
        upper = bin_search(arr, i + 1, n - 1, r - arr[i], Bound.UPPER)
        print(f'Iteration {i + 1} , {arr[i]}')
        print(f'  Searching LOWER bound (i.e. >=) for {l - arr[i]}: >> {arr[lower] if lower != -1 else lower}')
        print(f'  Searching UPPER bound (i.e. <=) for {r - arr[i]}: >> {arr[upper] if upper != -1 else upper}')
        
        if (lower == not_found or
            upper == not_found):
           continue
        index_pairs += upper - lower + 1
    return index_pairs

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())