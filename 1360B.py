def input_as_list():
    return list(map(int, input().split()))

if __name__=='__main__':
    tests = int(input())
    for _ in range(tests):
        [athlets] = input_as_list()
        strengths = input_as_list()
        strengths.sort()
        mimimum_gap = strengths[-1]
        for i in range(athlets - 1):
            if mimimum_gap > (strengths[i + 1] - strengths[i]):
                mimimum_gap = (strengths[i + 1] - strengths[i])
        print(mimimum_gap)