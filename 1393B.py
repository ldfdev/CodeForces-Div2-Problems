from collections import Counter

f = lambda : list(map(int, input().split()))
f()
planks = Counter(f())
rectangular_shape, square_shape = 0, 0

for l in planks:
    square_shape += planks[l] // 4
    rectangular_shape += (planks[l] % 4) // 2

for _ in range(int(input())):
    [event_type, x] = input().split()
    x = int(x)
    if event_type == '+':
        if x in planks:
            planks[x] += 1
        else:
            planks[x] = 1
        if planks[x] // 4 > (planks[x] - 1) // 4:
            square_shape += 1
            rectangular_shape -= 1
        elif planks[x] % 2 == 0:
            rectangular_shape += 1
    elif event_type == '-':
        planks[x] -= 1
        if planks[x] // 4 < (1 + planks[x]) // 4:
            square_shape -= 1
            rectangular_shape += 1
        elif planks[x] % 2 == 1:
            rectangular_shape -= 1
    
    answer = 'No'
    if square_shape > 1:
        answer = 'Yes'
    elif square_shape > 0:
        if rectangular_shape >= 2:
            answer = 'Yes'
    
    print(answer)
