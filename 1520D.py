def solve():
    n = int(input())
    arr = [int(x) for x in input().strip().split()]
    arr = [item - pos for pos, item in enumerate(arr, start=1)]
    arr.sort()
    arr.append(arr[0] - 1) # junk value used to flush the result of last computation
    total_pairs, first_item, item_count = 0, arr[0], 1
    for item in arr[1:]:
        if item == first_item:
            item_count += 1
            continue
        total_pairs += (item_count - 1) * item_count // 2
        first_item, item_count = item, 1
    return total_pairs

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())