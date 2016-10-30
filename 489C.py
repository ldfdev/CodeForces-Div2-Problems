from operator import ne as ne
n,s=map(int,input().split(" "))
min=max=-1
if s<1:
    if n==1:
        print("0 0")
    else:
        print(min,max,sep=' ')
elif 9*n < s:
    print(min,max,sep=' ')
else:
    if n==1:
        min=max=s
        print(min,max,sep=' ')
    else:
        min=max=[0]*n
        j=n-1
        ss=sum(min)
        SS=sum(max)
        while(ne(s,ss)):
            for num in range(9,-1,-1):
                if(num+ss<=s):
                    min[j]=num
                    j-=1
                    ss+=num
                    break
                else:
                    pass
        max=min[::-1]
        if min[0]==0:
            for i in range(1,n):
                if min[i]>0:
                    min[i]-=1
                    min[0]=1
                    break
        print(*min,sep="",end=" ")
        print(*max,sep="")
