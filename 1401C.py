for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    # check if array is already nondecreasing
    nondecreasing = True
    for i in range(1, n):
        if arr[i - 1] > arr[i]:
            nondecreasing = False
            break
    if nondecreasing:
        print('Yes')
    else:
        #determine how many elements need be changed
        can_be_gcded = True
        min_element = min(arr)
        sorted_array = sorted(arr)
        for i in range(n):
            if arr[i] == sorted_array[i]:
                continue
            if arr[i] % min_element != 0:
                can_be_gcded =False
                break
        if can_be_gcded == True:
            print('Yes')
        else:
            print('No')
        