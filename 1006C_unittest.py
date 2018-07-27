import unittest
from cf_1006_C import solve
class Test(unittest.TestCase):
    def test_scenario1(self):
        s = solve(
            5,
            [1, 3, 1, 1, 4])
        self.assertEqual(s, 5)
    def test_scenario2(self):
        s = solve(
            5,
            [1, 3, 2, 1, 4])
        self.assertEqual(s, 4)
    def test_scenario3(self):
        s = solve(
            3,
            [4, 1, 2])
        self.assertEqual(s, 0)

if __name__=='__main__':
    unittest.main()