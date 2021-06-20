# import unittest
from itertools import permutations
import copy

def solve(rounds, alice, bob):
    rock, scissors, paper = 0, 1, 2
    winning_strategies = set()
    winning_strategies.add((rock, scissors))
    winning_strategies.add((scissors, paper))
    winning_strategies.add((paper, rock))
    all_games = [(rock, rock),
                (rock, scissors),
                (rock, paper),
                (scissors, paper),
                (scissors, scissors),
                (scissors, rock),
                (paper, paper),
                (paper, rock),
                (paper, scissors)]

    def winning_alice():
        min_gain, max_gain = -1, -1
        for game in permutations(all_games):
            potential_gain = 0
            w, l = copy.deepcopy(alice), copy.deepcopy(bob)
            for m in game:
                if (sum(w) == 0) or (sum(l) == 0):
                    break
                g = min(w[m[0]], l[m[1]])
                if m in winning_strategies:
                    potential_gain += g
                w[m[0]] -= g
                l[m[1]] -= g
            max_gain = max(max_gain, potential_gain)
            min_gain = min(min_gain, potential_gain)
            if min_gain == -1:
                min_gain = potential_gain
        return (min_gain, max_gain)
    
    return winning_alice()


# class TestSolveMethods(unittest.TestCase):

#     def test_1(self):
#         inp = '''2
# 0 1 1
# 1 1 0'''.split('\n')
#         rounds = int(inp[0])
#         alice = [int(x) for x in inp[1].split()]
#         bob   = [int(x) for x in inp[2].split()]
#         self.assertEqual(solve(rounds, alice, bob), (0, 1))

#     def test_2(self):
#         inp = '''15
# 5 5 5
# 5 5 5
# '''.split('\n')
#         rounds = int(inp[0])
#         alice = [int(x) for x in inp[1].split()]
#         bob   = [int(x) for x in inp[2].split()]
#         self.assertEqual(solve(rounds, alice, bob), (0, 15))

#     def test_3(self):
#         inp = '''3
# 0 0 3
# 3 0 0
# '''.split('\n')
#         rounds = int(inp[0])
#         alice = [int(x) for x in inp[1].split()]
#         bob   = [int(x) for x in inp[2].split()]
#         self.assertEqual(solve(rounds, alice, bob), (3, 3))

#     def test_4(self):
#         inp = '''686
# 479 178 29
# 11 145 530
# '''.split('\n')
#         rounds = int(inp[0])
#         alice = [int(x) for x in inp[1].split()]
#         bob   = [int(x) for x in inp[2].split()]
#         self.assertEqual(solve(rounds, alice, bob), (22, 334))

#     def test_5(self):
#         inp = '''319
# 10 53 256
# 182 103 34
# '''.split('\n')
#         rounds = int(inp[0])
#         alice = [int(x) for x in inp[1].split()]
#         bob   = [int(x) for x in inp[2].split()]
#         self.assertEqual(solve(rounds, alice, bob), (119, 226))


if __name__=='__main__':
    rounds = int(input().strip())
    alice = [int(x) for x in input().strip().split()]
    bob   = [int(x) for x in input().strip().split()]
    min_score, max_score = solve(rounds, alice, bob)
    print(f'{min_score} {max_score}')
    # unittest.main()