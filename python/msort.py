import math

FLAG = 10000

def merge(A, p, q, r):
    n1 = q - p
    n2 = r - q
    L = []
    R = []
    for i in range(n1):
        L.append(A[p + i])
    for j in range(n2):
        R.append(A[q + j])
    L.append(FLAG)
    R.append(FLAG)
    i = j = 0
    for k in range(p, r):
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1

def MergeSort(A, p, r):
    if (r - p) >= 2:
        q = math.floor((r + p) / 2)
        MergeSort(A, p, q)
        MergeSort(A, q, r)
        merge(A, p, q, r)
