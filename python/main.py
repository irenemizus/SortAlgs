import math
import random
import time

import qsort
import msort


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    length = 12
    max_len = 10000000

    # Reference sorting by a standard Python tool
    L_ref = [random.randint(0, msort.MAX) for i in range(max_len)]
    sec_i_ref = time.time()
    L_ref.sort()
    sec_f_ref = time.time()

    time_ref = sec_f_ref - sec_i_ref
    print(f"Standard Python List sort for 10M items: {time_ref:.6f}")

    # QuickSortRecursive
    L_rec = random.sample(range(0, msort.MAX), length)
    print("Initial list for QuickSortRecursive: ", L_rec)

    s = 3
    Ls = qsort.rand_select(L_rec, 0, len(L_rec) - 1, s)
    print(f"The {s}-th element of the list: {Ls}")

    qsort.QuickSortRecursive(L_rec, 0, len(L_rec) - 1)
    print("Sorted list for QuickSortRecursive: ", L_rec)

    print()

    # QuickSort
    L = random.sample(range(0, msort.MAX), length)
    print("Initial list for QuickSort: ", L)

    qsort.QuickSortLinkedList(L, 0, len(L) - 1)
    print("Sorted list for QuickSort: ", L)

    print()

    # QuickSortSimpleList
    L_sl = random.sample(range(0, msort.MAX), length)
    print("Initial list for QuickSortSimpleList: ", L_sl)

    qsort.QuickSortSimpleList(L_sl, 0, len(L_sl) - 1)
    print("Sorted list for QuickSortSimpleList: ", L_sl)

    print()

    # MergeSortRecursive
    IN_rec = random.sample(range(0, msort.MAX), length)
    print("Initial list for MergeSortRecursive: ", IN_rec)

    p_rec = 0
    r_rec = len(IN_rec)
    msort.MergeSortRecursive(IN_rec, p_rec, r_rec, None)
    print("Sorted list for MergeSortRecursive: ", IN_rec)

    print()

    # MergeSort
    IN = random.sample(range(0, msort.MAX), length)
    print("Initial list for MergeSort: ", IN)

    p = 0
    r = len(IN)
    msort.MergeSortSimpleList(IN, p, r)
    print("Sorted list for MergeSort: ", IN)

    print()

    IN_sl = random.sample(range(0, msort.MAX), length)
    print("Initial list for MergeSortSimpleList: ", IN_sl)

    p = 0
    r = len(IN)
    msort.MergeSortSimpleList(IN_sl, p, r)
    print("Sorted list for MergeSortSimpleList: ", IN_sl)

    print()

    # Getting performance statistics
    print("\nLength\tT_qsr\tT_msr\tT_qsll\tT_msll\tT_qssl\tT_mssl")
    step = math.pow(2.0, 1.0 / 5)
    len_L_d = 8
    random.seed(0)
    while len_L_d < max_len:
        len_L = int(len_L_d)
        print(f"{len_L}\t", end='') # Length of the array

        # Generating an array of the given length
        L_init = [random.randint(0, msort.MAX) for i in range(len_L)]  #  random.sample(range(0, msort.MAX), len_L)

        # Making copies of L_init for the algorithms in comparison:
        # QuickSort
        L_qs = []
        L_qs[:] = L_init[:]
        # QuickSortSimpleList
        L_qssl = []
        L_qssl[:] = L_init[:]
        # QuickSortRecursive
        L_qsr = []
        L_qsr[:] = L_init[:]
        # MergeSort
        L_ms = []
        L_ms[:] = L_init[:]
        # MergeSortSimpleList
        L_mssl = []
        L_mssl[:] = L_init[:]
        # MergeSortRecursive
        L_msr = []
        L_msr[:] = L_init[:]

        # Measuring time performance for the algorithms in comparison:
        # Recursive algorithms
        # QuickSort
        sec_i_qsr = time.time()
        qsort.QuickSortRecursive(L_qsr, 0, len_L - 1)
        sec_f_qsr = time.time()

        time_qsr = sec_f_qsr - sec_i_qsr
        print(f"{time_qsr:.6f}\t", end='')

        # MergeSort
        sec_i_msr = time.time()
        msort.MergeSortRecursive(L_msr, 0, len_L, None)
        sec_f_msr = time.time()

        time_msr = sec_f_msr - sec_i_msr
        print(f"{time_msr:.6f}\t", end='')

        # Non-recursive algorithms with self-made linked lists
        # QuickSort
        sec_i_qs = time.time()
        qsort.QuickSortLinkedList(L_qs, 0, len_L - 1)
        sec_f_qs = time.time()

        time_qs = sec_f_qs - sec_i_qs
        print(f"{time_qs:.6f}\t", end='')

        # MergeSort
        sec_i_ms = time.time()
        msort.MergeSortLinkedList(L_ms, 0, len_L)
        sec_f_ms = time.time()

        time_ms = sec_f_ms - sec_i_ms
        print(f"{time_ms:.6f}\t", end='')

        # Non-recursive algorithms with built-in lists
        # QuickSortSimpleList
        sec_i_qssl = time.time()
        qsort.QuickSortSimpleList(L_qssl, 0, len_L - 1)
        sec_f_qssl = time.time()

        time_qssl = sec_f_qssl - sec_i_qssl
        print(f"{time_qssl:.6f}\t", end='')

        # MergeSortSimpleList
        sec_i_mssl = time.time()
        msort.MergeSortSimpleList(L_mssl, 0, len_L)
        sec_f_mssl = time.time()

        time_mssl = sec_f_mssl - sec_i_mssl
        print(f"{time_mssl:.6f}")


        len_L_d = len_L_d * step
