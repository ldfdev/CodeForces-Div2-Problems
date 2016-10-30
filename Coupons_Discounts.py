days=int(input())
teams=[int(x) for x in input().split(' ')]
remains = 0
for y in range(days):
    if y==0 and teams[0]%2==1:
        remains=1
    elif teams[y]==0 and remains==1:
        remains = 1
        break
    elif y==days-1 and remains==1 and teams[y]%2==0:
        remains = 1
        break
    else:
        if remains==1 and teams[y]%2==1:
            remains=0
        elif remains==0 and teams[y]%2==1:
            remains=1
if remains==0:
    print("YES")
else:
    print("NO")
