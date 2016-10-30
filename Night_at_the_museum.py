s=list(input())
s=[ord(ss)-97 for ss in s]
pointer = 0
rots = 0
#print(s)
for x in range(len(s)):
    if s[x]>13:
        s[x]=s[x]-26
#print(s)
for x in s:
    diff=abs(x-pointer)
    if diff>13:
        diff=26-diff
    rots+=diff
    pointer=x
print(rots)
