def initial_step(scores, sum_ = 0, bad_pointer = None):
    if not bad_pointer:
        scores.sort()
        sum_ = sum(scores)
        bad_pointer = len(scores) // 4
        sum_ -= sum(scores[:bad_pointer])
        return sum_, bad_pointer

def one_step(sum_, bad_pointer, new_value, scores, n):
    sum_ += new_value
    new_bad = n // 4
    diff = n - len(scores)

    if new_bad < bad_pointer + n - len(scores):
        sum_ += scores[new_bad - 1]
        return sum_, new_bad
    return sum_, bad_pointer

def solve():
    n = int(input())
    my_score   = [int(x) for x in input().split()]
    ilya_score = [int(x) for x in input().split()]
    my_overall, my_bad_pointer = initial_step(my_score)
    ilya_overall, ilya_bad_pointer = initial_step(ilya_score)
    needed = 0
    # print(f'My score {my_overall}')
    # print(f'Ilya     {ilya_overall}')
    old_n = n
    while my_overall < ilya_overall:
        needed += 1
        n += 1
        my_overall += 100
        if n % 4 == 0:
            my_overall -= my_score[my_bad_pointer]
            my_bad_pointer += 1
        diff = n - old_n
        new_ilya_bad_pointer = n // 4 - diff
        if new_ilya_bad_pointer < 0:
            continue
        assert ilya_bad_pointer >= new_ilya_bad_pointer
        for j in range(ilya_bad_pointer - 1, new_ilya_bad_pointer - 1, -1):
            ilya_overall += ilya_score[j]
        ilya_bad_pointer = new_ilya_bad_pointer
        # print(f' [{needed}] - My score {my_overall}')
        # print(f' [{needed}] - Ilya     {ilya_overall}')
        
    return needed

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())