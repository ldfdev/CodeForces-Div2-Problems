ne,c=map(int,input().split(' '))
v=[int(x) for x in input().split(' ')]
minn = 0
count = 1
if(ne==1):
    print('1')
else:
    for i in range(1,ne):
        if(v[i]-v[i-1]<=c):
            count+=1
        else:
            count=1
        if(count>minn):
            minn=count
    print(count)
