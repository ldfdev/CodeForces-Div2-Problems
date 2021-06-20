def optimal_play(alice_stamina, bob_stamina, first_is_alice=True):
    if bob_stamina == 0:
        return (alice_stamina, 0)
    if alice_stamina == 0:
        return (0, bob_stamina)

    return (alice_stamina - 1, bob_stamina)
    


def solve():
    alice_stamina, bob_stamina = map(int, input().split())
    return ' '.join(map(str, optimal_play(alice_stamina, bob_stamina)))

if __name__=='__main__':
    for _ in range(int(input())):
        print(solve())