def input_as_list():
    return list(map(int, input().split()))

def solve():
    [n] = input_as_list()
    
    values = input_as_list()
    types  = input_as_list()
    zero_type_values = set(map(lambda x: x[0], filter(lambda x: x[1] == 0, zip(values, types))))
    one_type_values  = set(map(lambda x: x[0], filter(lambda x: x[1] == 1, zip(values, types))))
    
    if (len(zero_type_values) > 0) and (len(one_type_values) > 0):
        return "Yes"
    s_values = sorted(values)
    for i in range(n):
        if s_values[i] != values[i]:
            return "no"
    return "Yes"

if __name__=='__main__':
    [tests] = input_as_list()
    for _ in range(tests):
        print(solve())