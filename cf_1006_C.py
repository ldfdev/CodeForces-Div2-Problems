n = int(input())
arr = [int(x) for x in input().split(' ')]

def solve(n, arr):
    leftSum = arr[0]; rightSum = arr[n - 1]
    i = 0; j = n - 1
    matches = list([0]) # print a zero if subsequest operations do not modify this set
    while i < j:
        # print("i={},j={},A={},C={}, leftSum={}, rightSum={}".format(i,j,arr[:i+1],arr[j:], leftSum, rightSum))
        if leftSum < rightSum:
            i = i + 1
            leftSum = leftSum + arr[i]
        elif rightSum < leftSum:
            j = j - 1
            rightSum = rightSum + arr[j]
        elif leftSum==rightSum: # case where a match is found
            # assert(leftSum==rightSum)
            # print("Equality i={},j={},A={},C={}, leftSum={}, rightSum={}".format(i,j,arr[:i+1],arr[j:], leftSum, rightSum))
            matches.append(leftSum)
            i = i + 1
            leftSum = leftSum + arr[i] # the other possibility with j can also be use instead
    return matches.pop()

if __name__=="__main__":
    print(solve(n, arr))