[n, m, sx, sy] = map(int, input().split())

moves = [(sx, sy), (sx, 1 ), (1 , 1 )]
visited = set(moves)
pos = (1, 1)
direction = 'down'
cnt = 1
while(cnt != n * m):
    # print('Curently pos is {}'.format(pos))
    cnt += 1
    (x, y) = pos
    if (direction == 'down'):
        if x == n:
            pos = (x, y + 1)
            direction = 'up'
        else:
            pos = (x + 1, y)
    else:
        if x == 1:
            pos = (x, y + 1)
            direction = 'down'
        else:
            pos = (x - 1, y)
    if pos not in visited:
        moves.append(pos)

for (x, y) in moves:
    print(x, y)