import re
def number__needed(a, b):
    counter = 0
    for letter in b:
        reg_exp=r"(" + re.escape(letter) + r")"
        x=re.search(reg_exp,a)
        if x:
            counter+=1

    return len(a)+len(b)-2*counter
def number_needed(a,b):
    counter = 0
    auxB=[False]*len(b)
    for ia in range(len(a)):
        for ib in range(len(b)):
            if a[ia] == b[ib]:
                if auxB[ib] ==False:
                    auxB[ib] = True
                    counter+=1
                    break
    return len(a)+len(b)-2*counter
a = input().strip()
b = input().strip()

print(number_needed(a, b))
