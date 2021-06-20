def solve():
    n = int(input().strip())
    arr = list(input())
    return [b for b in arr if b == 'b'] + [nb for nb in arr if nb != 'b']


if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(''.join(solve()))