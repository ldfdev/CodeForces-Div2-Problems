def inp():
    return list(map(int, input().split()))

def solve():
    (black, white) = ('*', '.')
    [n, m, priceOf1, priceOf2] = inp()
    theaterPaves = []
    for _ in range(n):
        theaterPaves.append(list(input()))
    cost = 0
    for i in range(n):
        for j in range(m):
            if theaterPaves[i][j] == black:
                continue
            if priceOf2 >= 2 * priceOf1:
                cost += priceOf1
            else:
                if j == (m - 1):
                    cost += priceOf1
                elif theaterPaves[i][j + 1] == white:
                    cost += priceOf2
                    theaterPaves[i][j + 1] = black
                else:
                    cost += priceOf1
    return cost
    
    
if __name__=='__main__':
    [tests] = inp()
    for _ in range(tests):
        print(solve())