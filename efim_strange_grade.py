def try_round_up(position,essai):
    if position==n-2: #is n-1 -1 form .
        return
    else:
        if grade[position+1] >= 5:
            if essai > 0:
                essai-=1
                grade[position]+=1
                grade[position+1:]=[0]*len(grade[position+1:])
        elif grade[position+1] == 4:
            essai = try_round_up(position+1,essai)
            if grade[position+1] >= 5:
                if essai > 0:
                    essai-=1
                    grade[position]+=1
                    grade[position+1:]=[0]*len(grade[position+1:])
        else:
            essay = try_round_up(position+1,essai)
    return essai
n,trials=map(int,input().split(' '))
grade=input()
for i in range(n):
    if grade[i]=='.':
        put = i # a la fin met le .
        grade=grade[:i]+grade[i+1:]
        break
grade=[int(a) for a in grade]
t = try_round_up(0,trials)
# remove trailing zeroes
while grade[-1]==0:
    x=len(grade)
    grade=grade[:x-1]
for i in range(len(grade)):
    if i==put:
        print('.',end='')
    print(grade[i],end='')
