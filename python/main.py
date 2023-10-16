import random

import qsort
import msort

# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    L = random.sample(range(0, 10000), 10)
    print("Initial list for QuickSort: ", L)

    s = 3
    Ls = qsort.rand_select(L, 0, len(L) - 1, s)
    print(f"The {s}-th element of the list: {Ls}")

    L = qsort.QuickSort(L, 0, len(L) - 1)
    print("Quick-sortred list: ", L)

    print()

    A = random.sample(range(0, msort.FLAG), 10)
    print("Initial list for MergeSort: ", A)

    msort.MergeSort(A, 0, len(A))
    print("Merge-sortred list: ", A)