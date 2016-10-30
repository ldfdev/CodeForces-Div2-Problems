n=int(input())
word=list(input())
counter = []
viz=[0]*n
for i in range(n):
    if word[i]=='B':
        if viz[i]==0:
            c=1
            viz[i]=1
            for j in range(i+1,n):
                if word[j]=='B':
                    c+=1
                    viz[j]=1
                else:
                    break
            counter.append(c)
print(len(counter))
if len(counter)>0:
    print(*counter, sep=' ')
