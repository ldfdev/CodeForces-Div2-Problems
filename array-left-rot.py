def array_left_rotation(a, n, k):
    a=list(a)
    a=a[k:]+a[:k]
    x=map(int,a)
    return x
n, k = map(int, input().strip().split(' '))
a = map(int, input().strip().split(' '))
answer = array_left_rotation(a, n, k);
print(*answer, sep=' ')
