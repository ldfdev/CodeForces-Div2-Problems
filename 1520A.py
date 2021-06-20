

def solve():
    days = int(input())
    tasks = list(input().strip())
    tasks.append('$') # used to process teh last item . add an extra item
    suspicious_tasks = set()
    current_task = None # used to deal withconsecutive days solvings ame task
    for task in tasks:
        if current_task is None:
            current_task = task
            continue
        if task in suspicious_tasks:
            return 'NO'
        if task != current_task:
            suspicious_tasks.add(current_task)
        current_task = task
    return 'YES'
    
if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())