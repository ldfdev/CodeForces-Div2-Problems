import unittest
from cf1003B import solve_1003B
class Test(unittest.TestCase):
    def test_scenario1(self):
        s = solve_1003B(2, 2, 1)
        self.assertEqual(s,list('1100'))
    def test_scenario2(self):
        s = solve_1003B(3, 3, 3)
        self.assertEqual(s,list('101100'))
    def test_scenario3(self):
        s = solve_1003B(5, 3, 6)
        self.assertEqual(s,list('01010100'))

if __name__=='__main__':
    unittest.main()