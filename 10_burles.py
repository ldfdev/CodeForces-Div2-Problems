k,r=map(int,input().split(' '))
k0=k
var=True
while(var):
    if (k-r)%10==0:
        print(k//k0)
        var=False
    elif k%10==0:
        print(k//k0)
        var=False
    else:
        k=k+k0
