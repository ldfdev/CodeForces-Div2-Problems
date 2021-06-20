

def solve():
    n, m = [int(x) for x in input().strip().split()]
    matrix, visited = [], []
    for _ in range(n):
        matrix.append([int(x) for x in input().strip().split()])
        visited.append([False] * m)
    stack = [0] * (n * m + 2)
    stack_index = 1
    stack[stack_index] = (0, 0)
    while stack_index > 0:
        x, y = stack[stack_index]
        stack_index -= 1
        if visited[x][y]:
            continue
        if y > 0:
            stack_index += 1
            stack[stack_index] = (x, y - 1)
            if matrix[x][y - 1] == matrix[x][y]:
                matrix[x][y] += 1
        
        if y < n - 1:
            stack_index += 1
            stack[stack_index] = (x, y + 1)
            if matrix[x][y + 1] == matrix[x][y]:
                pass

        if x > 0:
            stack_index += 1
            stack[stack_index] = (x - 1, y)
            if matrix[x - 1][y] == matrix[x][y]:
                pass
        
        if x < n - 1:
            stack_index += 1
            stack[stack_index] = (x + 1, y)
            if matrix[x + 1][y] == matrix[x][y]:
                pass
        visited[x][y] = True

    for i in range(n):
        print(' '.join(map(str, matrix[i])))
    
if __name__ == '__main__':
    for _ in range(int(input().strip())):
        solve()