from collections import Counter

queries = int(input())
for _ in range(queries):
	n = int(input())
	numbers = Counter([int(x) for x in input().split()])
	(t, quantity) = (2048, 1)
	while(t > 0):
		if numbers[t] >= quantity:
			print('YES'); break
		elif numbers[t] > 0:
			quantity -= numbers[t]
		(t, quantity) = (t // 2, quantity * 2)
	if t == 0:
		print('NO')
	
