n,k=map(int,input().split(' '))
passwords=list()
for i in range(n):
    x=input()
    lx=len(x)
    passwords.append([lx,x])
correct_pass=input()
len_correct_pass=len(correct_pass)
passwords.sort(key=lambda x:x[0])
#print(*passwords,sep=' ')
best=0
worst=0
trials=0
#Compute best case
for i in range(n):
    if passwords[i][0]==len_correct_pass:
        c = 0 #alte stringuri cu aceeasi lungime
        for j in range(i+1,n):
            if passwords[j][0]==len_correct_pass:
                c+=1
        best=1+trials+5*(trials//k)
        worst=1+trials+c+5*((trials+c)//k)
        print(best,worst)
        break
    else:
        trials+=1
