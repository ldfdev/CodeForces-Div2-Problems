from enum import Enum

class T(str, Enum):
    ZERO='0',
    ONE='1',
    TWO='2'

def searchKey(array,key,start_pos):
    MAX_LIMIT = len(array)
    while start_pos < MAX_LIMIT:
        if array[start_pos] == key:
            return start_pos
        start_pos = start_pos + 1
    raise LookupError

def swapPositions(tern, index, fin):
    L = len(tern)
    assert(index < L and fin < L)
    k = tern[fin]
    for i in range(fin, index, -1):
        tern[i] = tern[i - 1]
    tern[index] = k


def solve(tern):
    L = len(tern)
    for index in range(L):
        if tern[index] == T.ZERO:
            pass
        elif tern[index] == T.ONE and index < L - 1:
            # move 1 to the right if doing so do not increase lexicographic order
            if tern[index + 1] == T.ZERO:
                tern[index] = T.ZERO
                tern[index + 1] = T.ONE
        elif tern[index] == T.TWO and index < L - 1:
            try:
                fin = searchKey(tern, key = T.ONE, start_pos = index + 1)
                swapPositions(tern, index, fin)
            except LookupError:
                pass
    return tern

def find(arr, item):
    L = len(arr)
    for x in range(L):
        if arr[x] == item:
            return x
    return L
    
def new_solve(arr):
    ones = len(list(filter(lambda x:x == T.ONE, arr)))
    new_arr = list(filter(lambda x:x != T.ONE, arr))
    key_pos = find(new_arr, T.TWO)
    # print('TWO position found at {}'.format(key_pos))
    return new_arr[:key_pos] + ['1']*ones + new_arr[key_pos:]

if __name__=="__main__":
    tern = input()
    print(''.join(new_solve(tern)))