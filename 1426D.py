# importing unittest causes NZEC on CodeForces
# import unittest

def solve(size, array):
    should_be_changed = 0
    # compute partial sums to detect if any subsegment sums to 0
    partial_sums = [i for i in array]
    sums = set([0, partial_sums[0]])
    for i in range(1, size):
        partial_sums[i] += partial_sums[i - 1]
        if (partial_sums[i] in sums):
            should_be_changed += 1
            partial_sums[i] = array[i]
            sums = set([0])
        sums.add(partial_sums[i])
    
    return should_be_changed


# class TestStringMethods(unittest.TestCase):

#     def test_1(self):
#         size = 4
#         array = [int(x) for x in '1 -5 3 2'.split()]
#         self.assertEqual(solve(size, array), 1)

#     def test_2(self):
#         size = 5
#         array = [int(x) for x in '4 -2 3 -9 2'.split()]
#         self.assertEqual(solve(size, array), 0)

#     def test_3(self):
#         size = 9
#         array = [int(x) for x in '-1 1 -1 1 -1 1 1 -1 -1'.split()]
#         self.assertEqual(solve(size, array), 6)

#     def test_4(self):
#         size = 8
#         array = [int(x) for x in '16 -5 -11 -15 10 5 4 -4'.split()]
#         self.assertEqual(solve(size, array), 3)

if __name__=='__main__':
    size = int(input().strip())
    array = [int(x) for x in input().strip().split()]
    print(solve(size, array))
    # unittest.main()
    