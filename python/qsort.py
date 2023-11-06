import random

def part(L, p, r):
    piv = L[r]
    i = p - 1
    for j in range(p, r):
        if L[j] <= piv:
            i = i + 1
            tmp = L[j]
            L[j] = L[i]
            L[i] = tmp
    L[r] = L[i + 1]
    L[i + 1] = piv
    return i + 1

def rand_part(L, p, r):
    piv_ind = random.randint(p, r)
    #print(piv_ind)
    tmp = L[r]
    L[r] = L[piv_ind]
    L[piv_ind] = tmp
    return part(L, p, r)

def QuickSortRecursive(L, p, r):
    if p < r:
        q = rand_part(L, p, r)
        if q > 0: QuickSortRecursive(L, p, q - 1)
        QuickSortRecursive(L, q + 1, r)

def rand_select(L, p, r, s):
    if p == r:
        return L[p]
    if p < r:
        q = rand_part(L, p, r)
        k = q - p + 1
        if s == k:
            return L[q]
        elif s < k:
            return rand_select(L, p, q - 1, s)
        else:
            return rand_select(L, q + 1, r, s - k)



