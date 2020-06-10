def odd(x):
    return ((x & 1) == 1)
def even(x):
    return not odd(x)

def input_as_list():
    return list(map(int, input().split()))

if __name__=='__main__':
    tests = int(input())
    for _ in range(tests):
        [n] = input_as_list()
        elems = input_as_list()
        odds  = list(filter(odd , elems))
        evens = list(filter(even, elems))
        answer = "YES"
        if (odd(len(odds))):
            #for sure if there are 2k+1 odd nums we also have 2q + 1 even nums
            answer = "NO"
            elems.sort()
            for i in range(n - 1):
                if elems[i] + 1 == elems[i + 1]:
                    answer = "YES"
                    break
        print(answer)
