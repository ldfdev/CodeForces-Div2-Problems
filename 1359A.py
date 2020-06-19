def inp():
    return list(map(int, input().split()))

def solve():
    [cards, jokers, players] = inp()
    if jokers == 0:
        return 0
    if cards == jokers:
        return 0
    lucky_player = cards // players
    if jokers <= lucky_player:
        return jokers
    jokers -= lucky_player
    if jokers % (players - 1) == 0:
        return lucky_player - (jokers // (players - 1))
    return lucky_player - 1 - (jokers // (players - 1))
    
if __name__=='__main__':
    [tests] = inp()
    for _ in range(tests):
        print(solve())