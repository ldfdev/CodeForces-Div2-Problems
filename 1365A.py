def input_as_list():
    return list(map(int, input().split()))

def solve():
    [n, m] = input_as_list()
    taken_rows = set()
    taken_columns = set()
    for i in range(n):
        row = input_as_list()
        if 1 in row:
            taken_rows.add(i)
            for j in range(m):
                if row[j] == 1:
                    taken_columns.add(j)
    free_rows    = n - len(taken_rows)
    free_columns = m - len(taken_columns)
    free = free_rows
    if free_columns < free_rows:
        free = free_columns
    if (free & 1):
        print("Ashish")
    else:
        print("Vivek")    

if __name__=='__main__':
    [tests] = input_as_list()
    for _ in range(tests):
        solve()