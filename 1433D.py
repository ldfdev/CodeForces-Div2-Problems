import collections

def solve():
    districts = int(input().strip())
    gangs = [int(x) for x in input().strip().split()]
    cgangs = collections.defaultdict(list)
    for g in range(districts):
        cgangs[gangs[g]].append(1 + g)
    if len(list(cgangs.keys())) < 2:
        print('NO')
        return
    print('YES')
    lk = list(cgangs.keys())
    for pos, k in enumerate(lk):
        dest = cgangs[lk[0]][0]
        if pos < len(lk) - 1:
            dest = cgangs[lk[pos + 1]][0]
            for x in cgangs[k]:
                print(x, dest)
        if pos == len(lk) - 1:
            if len(cgangs[k]) > 1:
                for x in cgangs[k][1:]:
                    print(x, dest) 
    
    

if __name__=='__main__':
    for _ in range(int(input().strip())):
        solve()