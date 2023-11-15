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


def ContainsSameEls(L, L_sort):
    for el in L:
        for i in range(len(L_sort)):
            if el == L_sort[i]:
                del(L_sort[i])
                break
    same_els = not L_sort

    return same_els


def MakeRandList(rnd: random.Random, max_el, el_numb):
    return rnd.sample(range(0, max_el), el_numb)


class IsSortedQuickSortSimpleList(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10
    attempts = 100

    def test_is_sorted(self):
        for att in range(self.attempts):
            L_init = MakeRandList(self.rnd, self.max, self.numb + att)
            L = []
            L[:] = L_init[:]
            qsort.QuickSortSimpleList(L, 0, len(L) - 1)
            self.assertTrue(IsSorted(L))  # add assertion here
            self.assertTrue(ContainsSameEls(L_init, L))


class IsSortedQuickSortLinkedList(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10
    attempts = 100

    def test_is_sorted(self):
        for att in range(self.attempts):
            L_init = MakeRandList(self.rnd, self.max, self.numb + att)
            L = []
            L[:] = L_init[:]
            qsort.QuickSortLinkedList(L, 0, len(L) - 1)
            self.assertTrue(IsSorted(L))  # add assertion here
            self.assertTrue(ContainsSameEls(L_init, L))


class IsSortedQuickSortRecursive(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10
    attempts = 100

    def test_is_sorted(self):
        for att in range(self.attempts):
            L_init = MakeRandList(self.rnd, self.max, self.numb + att)
            L = []
            L[:] = L_init[:]
            qsort.QuickSortRecursive(L, 0, len(L) - 1)
            self.assertTrue(IsSorted(L))  # add assertion here
            self.assertTrue(ContainsSameEls(L_init, L))


class IsSortedMergeSortSimpleList(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10
    attempts = 100

    def test_is_sorted(self):
        for att in range(self.attempts):
            L_init = MakeRandList(self.rnd, self.max, self.numb + att)
            L = []
            L[:] = L_init[:]
            msort.MergeSortSimpleList(L, 0, len(L))
            self.assertTrue(IsSorted(L))  # add assertion here
            self.assertTrue(ContainsSameEls(L_init, L))


class IsSortedMergeSortLinkedList(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10
    attempts = 100

    def test_is_sorted(self):
        for att in range(self.attempts):
            L_init = MakeRandList(self.rnd, self.max, self.numb + att)
            L = []
            L[:] = L_init[:]
            msort.MergeSortLinkedList(L, 0, len(L))
            self.assertTrue(IsSorted(L))  # add assertion here
            self.assertTrue(ContainsSameEls(L_init, L))


class IsSortedMergeSortRecursive(unittest.TestCase):
    rnd = random.Random(0)
    max = 10000
    numb = 10
    attempts = 100

    def test_is_sorted(self):
        for att in range(self.attempts):
            L_init = MakeRandList(self.rnd, self.max, self.numb + att)
            L = []
            L[:] = L_init[:]
            msort.MergeSortRecursive(L, 0, len(L), None)
            self.assertTrue(IsSorted(L))  # add assertion here
            self.assertTrue(ContainsSameEls(L_init, L))


if __name__ == '__main__':
    unittest.main()
