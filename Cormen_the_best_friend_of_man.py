days,k=map(int,input().split(' '))
shed=[int(x) for x in input().split(' ')]
tot=0
for i in range(days-1):
    if shed[i]+shed[i+1]<k:
        toty=k-shed[i+1]-shed[i]
        shed[i+1]=shed[i+1]+toty
        tot+=toty
print(tot)
print(*shed,sep=' ')
