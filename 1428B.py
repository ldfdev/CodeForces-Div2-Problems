def solve():
    n = int(input().strip())
    conveyors = list(input().strip())
    def run(start, lookup):
        target = start
        while conveyors[start] in lookup:
            start = (start + 1) % n
            if start == target:
                return True
        return False
    
    if run(0, '->'):
        return n
    if run(0, '-<'):
        return n
    
    direct_reachable = set()
    for c in range(n):
        if conveyors[c] == '-':
            direct_reachable.add(c)
            direct_reachable.add((c + 1) % n)
    return len(direct_reachable)

if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())