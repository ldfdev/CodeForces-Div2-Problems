def input_as_list():
    return list(map(int, input().split()))

[n] = input_as_list()
a = input_as_list()
b = input_as_list()

mapping = dict()
for i in range(n):
    mapping[b[i]] = i

diffs = dict()

for i in range(n):
    key = i - mapping[a[i]]
    if key < 0:
        key = n + key
    # print('element {e} will match after {d} shifts'.format(e=a[i], d=key))
    if key in diffs:
        diffs[key] += 1
    else:
        diffs[key] = 1
solution = 0
for k in diffs:
    if diffs[k] > solution:
        solution = diffs[k]

print(solution)