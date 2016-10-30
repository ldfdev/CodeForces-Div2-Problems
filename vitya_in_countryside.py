import sys

n=int(input())
arr=[int(a) for a in input().strip().split(' ')]
if n==1:
    if arr[0]==0:
        print('UP')
    elif arr[0]==15:
        print('DOWN')
    else:
        print('-1')
elif arr[-2]<arr[-1]:
    if arr[-1] < 15:
        print('UP')
    else:
        print('DOWN')
else:
    if arr[-1]==0:
        print('UP')
    else:
        print('DOWN')
