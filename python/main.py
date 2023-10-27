import random

import qsort
import msort

# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    L = random.sample(range(0, msort.MAX), 10)
    print("Initial list for QuickSort: ", L)

    s = 3
    Ls = qsort.rand_select(L, 0, len(L) - 1, s)
    print(f"The {s}-th element of the list: {Ls}")

    L = qsort.QuickSort(L, 0, len(L) - 1)
    print("Quick-sorted list: ", L)

    print()

    #IN = [60, 33, 16, 99, 78, 35, 97, 26, 12, 67, 10]
    # OUT = [-1] * len(IN)
    # msort.merge(IN, 0, 0, 3, OUT)
    # print(OUT)

    IN = random.sample(range(0, msort.MAX), 12)
    print("Initial list for MergeSort: ", IN)

    p = 3
    r = 8 #len(IN)
    msort.MergeSort(IN, p, r)
    print("Merge-sorted list: ", IN)