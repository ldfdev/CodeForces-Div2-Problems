import sys

def func(n,b):
		d=dict()	
		s=""
		for bb in self.b:
				if bb in d:
            d[bb]+=1	
				else:
						d[bb]=1    
    if "_" in d:
        for x in b:
            if d[x]==1:
                if x=="_":
                    pass
                else:
                    s="NO"
                    break
        if s=="NO":
        		pass
        else:
        		s="YES"
    else:
        for i in range(n):
            if i==0:
                if b[i]==b[i+1]:
                    pass
                else:
                    s="NO"
                    break
            elif i<n-1:
                if b[i]==b[i+1] or b[i-1]==b[i]:
                    pass
                else:
                    s="NO"
                    break
            else:
                if b[i-1]==b[i]:
                    s="YES"
                else:
                    s="NO"
    return s

Q = int(input().strip())
for a0 in range(Q):
    n = int(input().strip())
    b = input().strip()
    print(func(n,b)+"\n")
