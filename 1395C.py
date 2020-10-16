f = lambda : list(map(int, input().split()))
[n, m], a, b = f(), f(), f()
best_solution = a[0] & b[0]
for j in range(1, m):
    best_solution = min(best_solution, a[0] & b[j])
for i in range(1, n):
    alternate_solution = best_solution | (a[i] & b[0])
    for j in range(1, m):
        alternate_solution = min(alternate_solution, best_solution | (a[i] & b[j]))
    best_solution = alternate_solution
print(best_solution)