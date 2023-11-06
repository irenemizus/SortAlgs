import math

MAX = 10000

def merge(IN, p, q, r, OUT):
    # n1 = q - p
    # n2 = r - q
    # L = []
    # R = []
    # for i in range(n1):
    #     L.append(A[p + i])
    # for j in range(n2):
    #     R.append(A[q + j])
    # L.append(FLAG)
    # R.append(FLAG)

    # i = j = 0
    # for k in range(p, r):
    #     if L[i] <= R[j]:
    #         A[k] = L[i]
    #         i = i + 1
    #     else:
    #         A[k] = R[j]
    #         j = j + 1

    i = k = p
    j = q
    while i < q and j < r and k < r:
        if IN[i] <= IN[j]:
            OUT[k] = IN[i]
            i = i + 1
        else:
            OUT[k] = IN[j]
            j = j + 1
        k = k + 1
    if i < q:
        OUT[k:r] = IN[i:q]
    if j < r:
        OUT[k:r] = IN[j:r]

def MergeSortRecursive(A, p, r, A_tmp):
    if A_tmp == None:
        A_tmp = []
    if (r - p) >= 2:
        q = math.floor((r + p) / 2)
        MergeSortRecursive(A, p, q, A_tmp)
        MergeSortRecursive(A, q, r, A_tmp)
        A_tmp[:] = A[:]
        merge(A_tmp, p, q, r, A)

def MergeSort(A, p, r):
    if p < r and r <= len(A):
        A_in = A
        A_out = A[:]

        indx = []
        for i in range(p, r + 1): indx.append(i)

        while len(indx) > 2:
            # Merging
            i = -1
            for i in range(len(indx) - 2, -1, -2):
                if i > 0:
                    merge(A_in, indx[i - 1], indx[i], indx[i + 1], A_out)
                else:
                    merge(A_in, indx[i], indx[i], indx[i + 1], A_out)

            for i in range(len(indx) - 2, 0, -2):
                del indx[i]

            tmp = A_in
            A_in = A_out
            A_out = tmp

        A[:] = A_in[:]