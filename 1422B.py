def fetch_ops(*args):
    args = sorted(*args)
    ret, L = 0, len(args)
    for i in range((L + 1) // 2):
        ret += args[L - 1 - i] - args[i]
    return ret

def solve():
    n, m = [int(x) for x in input().strip().split()]
    matrix = []
    cost = 0
    for r in range(n):
        matrix.append([int(x) for x in input().strip().split()])
    n_lim, m_lim = (n + 1) // 2, (m + 1) // 2
    for r in range(n_lim):
        for c in range(m_lim):
            l = []
            if r == n - 1 - r:
                if c == m - 1 - c:
                    continue
                else:
                    cost += fetch_ops([matrix[r][c],
                                       matrix[r][m - 1 - c]])
            else:
                if c == m - 1 - c:
                    cost += fetch_ops([matrix[r][c],
                                       matrix[n - 1 - r][c]])
                else:
                    cost += fetch_ops([matrix[r][c],
                                       matrix[r][m - 1 - c],
                                       matrix[n - 1 - r][c],
                                       matrix[n - 1 - r][m - 1 - c]])
    return cost
    
if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())