import sys,copy

n=int(input())
roaches=list(input().strip())
roaches2=copy.deepcopy(roaches)
#case 1: 1st cockroach unchanged
b_swaps = 0
r_swaps = 0
for i in range(1,n):
    if roaches[i]=='b':
        if roaches[i-1]=='b':
            roaches[i]='r'
            b_swaps+=1
    else:
        if roaches[i-1]=='r':
            roaches[i]='b'
            r_swaps+=1
sol1=max(r_swaps,b_swaps)
#case 2: 1st cockroach changed
b_swaps = 0
r_swaps = 0
#print('Initial...',*roaches,sep=' ')
#print('Initial2...',*roaches2,sep=' ')
if roaches2[0]=='b':
    roaches2[0]='r'
    b_swaps+=1
else:
    roaches2[0]='b'
    r_swaps+=1
for i in range(1,n):
    if roaches2[i]=='b':
        if roaches2[i-1]=='b':
            roaches2[i]='r'
            b_swaps+=1
    else:
        if roaches2[i-1]=='r':
            roaches2[i]='b'
            r_swaps+=1
sol2=max(r_swaps,b_swaps)
#print('r_swaps',r_swaps,'b_swaps',b_swaps)
print(sol1 if sol1<sol2 else sol2)
#print(sol2)
