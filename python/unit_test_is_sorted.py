import unittest
import random

import msort
import qsort


def IsSorted(L):
    is_sorted = True
    for i in range(1, len(L)):
        if L[i - 1] > L[i]:
            is_sorted = False
            break
    return is_sorted

def MakeRandList(rnd: random.Random, max_el, el_numb):
    return rnd.sample(range(0, max_el), el_numb)

class IsSortedQuickSort(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10

    def test_is_sorted(self):
        L = MakeRandList(self.rnd, self.max, self.numb)
        L = qsort.QuickSort(L, 0, len(L) - 1)
        self.assertTrue(IsSorted(L))  # add assertion here

class IsSortedMergeSort(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10

    def test_is_sorted(self):
        L = MakeRandList(self.rnd, self.max, self.numb)
        msort.MergeSort(L, 0, len(L))
        self.assertTrue(IsSorted(L))  # add assertion here

if __name__ == '__main__':
    unittest.main()
