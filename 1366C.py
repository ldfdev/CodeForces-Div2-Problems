def as_list():
    return list(map(int, input().split()))
# A correct matrix lokks like this
# a b c d
# b c d
# c d
# d
#            d
#          d c
#        d c b
#      d c b a

def solve():
    matrix = []
    [n, m] = as_list()
    for i in range(n):
        matrix.append(as_list())
    path_length = (m + n - 1) // 2
    classes = []
    for _ in range(path_length):
        classes.append([0,0])
    for r in range(n):
        for c in range(m):
            _class = r + c
            if _class >= path_length:
                _class = n + m - 2 - _class
            if _class >= path_length:
                continue
            classes[_class][matrix[r][c]] += 1
    cost = 0
    for i in range(path_length):
        cost += min(classes[i][0], classes[i][1])
    return cost

if __name__=='__main__':
    [tests] = as_list()
    for _ in range(tests):
        print(solve())