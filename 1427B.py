import itertools

def remove_beginning(lst, bad):
    idx = 0
    while lst[idx] == bad:
        idx += 1
        if len(lst) == idx:
            break
    return idx

def solve():
    n, k = [int(x) for x in input().strip().split()]
    game_scores = list(input().strip())
    win, lose = 'W', 'L'

    first_good_pos = remove_beginning(game_scores, lose)
    first_range = first_good_pos
    game_scores = game_scores[first_good_pos:]
    # print(f'Games after removing from head {game_scores}')
    game_scores.reverse()
    if not game_scores:
        return max(2 * min(k, first_range) - 1, 0)
    last_good_pos = remove_beginning(game_scores, lose)
    last_range = last_good_pos
    game_scores = game_scores[last_good_pos:]
    game_scores.reverse()
    # print(f'Games after removing from tail {game_scores}, {last_range}')
    
    assignable_points_from_list_ends = first_range + last_range

    lose_lengths = []
    for key, group in itertools.groupby(game_scores):
        lose_lengths.append([key, len(list(group))])
    # print(lose_lengths)
    initial_points = sum(map(lambda t: 0 if t[0] == lose else 2 * t[1] - 1, lose_lengths))
    # print(f'Initial points {initial_points}. Assignable points from bounds {assignable_points_from_list_ends}')
    lose_lengths = list(filter(lambda t: t > 0, map(lambda t: 0 if t[0] == win else t[1], lose_lengths)))
    if n == 1:
        if game_scores[0] == win:
            return 1
        return 1 if (k == 1) else 0
    # print(lose_lengths)
    lose_lengths.sort()
    for l in lose_lengths:
        if k >= l:
            k, initial_points = k - l, initial_points + 2 * (l - 1) + 3
        else:
            k, initial_points = 0, initial_points + 2 * k

    initial_points += 2 * min (k, assignable_points_from_list_ends)
    return initial_points


if __name__=='__main__':
    for _ in range(int(input().strip())):
        print(solve())