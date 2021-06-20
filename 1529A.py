def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    min_element = min(a)
    good_for_deletion = [x for x in a if x > min_element]
    return len(good_for_deletion)

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())