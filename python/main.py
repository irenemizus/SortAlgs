import math
import random
import time

import qsort
import msort

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # QuickSortRecursive
    L_rec = random.sample(range(0, msort.MAX), 10)
    print("Initial list for QuickSortRecursive: ", L_rec)

    s = 3
    Ls = qsort.rand_select(L_rec, 0, len(L_rec) - 1, s)
    print(f"The {s}-th element of the list: {Ls}")

    qsort.QuickSortRecursive(L_rec, 0, len(L_rec) - 1)
    print("Sorted list for QuickSortRecursive: ", L_rec)

    print()

    # MergeSort
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

    print()

    # MergeSortRecursive
    IN_rec = random.sample(range(0, msort.MAX), 12)
    print("Initial list for MergeSortRecursive: ", IN_rec)

    p_rec = 0
    r_rec = len(IN_rec)
    msort.MergeSortRecursive(IN_rec, p_rec, r_rec, None)
    print("MergeRecursive-sorted list: ", IN_rec)

    # Getting performance statistics
    print("\nLength\tT_qsr\tT_ms\tT_msr")
    step = math.pow(2.0, 1.0 / 5)
    len_L_d = 8
    while len_L_d < 10000000:
        len_L = int(len_L_d)
        print(f"{len_L}\t", end='') # Length of the array

        # Generating an array of the given length
        L_init = [random.randint(0, msort.MAX) for i in range(len_L)]  #  random.sample(range(0, msort.MAX), len_L)

        # Making copies of L_init for the algorithms in comparison:
        # QuickSortRecursive
        L_qsr = []
        L_qsr[:] = L_init[:]
        # MergeSort
        L_ms = []
        L_ms[:] = L_init[:]
        # MergeSortRecursive
        L_msr = []
        L_msr[:] = L_init[:]

        # Measuring time performance for the algorithms in comparison:
        # QuickSortRecursive
        sec_i_qsr = time.time()
        qsort.QuickSortRecursive(L_qsr, 0, len_L - 1)
        sec_f_qsr = time.time()

        time_sqr = sec_f_qsr - sec_i_qsr
        print(f"{time_sqr:.6f}\t", end='')

        # MergeSort
        sec_i_ms = time.time()
        msort.MergeSort(L_ms, 0, len_L)
        sec_f_ms = time.time()

        time_ms = sec_f_ms - sec_i_ms
        print(f"{time_ms:.6f}\t", end='')

        # MergeSortRecursive
        sec_i_msr = time.time()
        msort.MergeSortRecursive(L_msr, 0, len_L, None)
        sec_f_msr = time.time()

        time_msr = sec_f_msr - sec_i_msr
        print(f"{time_msr:.6f}")

        len_L_d = len_L_d * step