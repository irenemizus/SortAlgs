import random

from indx_list import indx_item, indx_add_next


def part(L, p, r):
    piv = L[r]
    i = p - 1
    for j in range(p, r):
        if L[j] < piv:
            i = i + 1
            tmp = L[j]
            L[j] = L[i]
            L[i] = tmp
    L[r] = L[i + 1]
    L[i + 1] = piv
    return i + 1


def rand_part(L, p, r):
    piv_ind = random.randint(p, r)
    tmp = L[r]
    L[r] = L[piv_ind]
    L[piv_ind] = tmp
    return part(L, p, r)


def QuickSortRecursive(L, p, r):
    if p < r:
        q = rand_part(L, p, r)
        if q > 0: QuickSortRecursive(L, p, q - 1)
        QuickSortRecursive(L, q + 1, r)


def QuickSortLinkedList(L, p, r):
    indx = indx_item(p)
    indx_first = indx
    indx_add_next(indx, r + 1)
    any_sorted = True

    indx = indx_first
    while any_sorted:
        any_sorted = False
        while indx.next is not None:
            p_i = indx.indx
            r_i = indx.next.indx
            if r_i - p_i > 1:
                q_i = rand_part(L, p_i, r_i - 1)
                any_sorted = True
                if p_i < q_i < r_i:
                    indx_add_next(indx, q_i)
                    break
                elif q_i == r_i:
                    indx_add_next(indx, q_i - 1)
                    break
                elif q_i == p_i:
                    indx_add_next(indx, p_i + 1)
                    break
            indx = indx.next


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


def QuickSortSimpleList(L, p, r):
    curs = list([p, r + 1])
    any_sorted = True

    i = 1
    while any_sorted:
        any_sorted = False
        lc = len(curs)
        while i < lc:
            p_i = curs[i - 1]
            r_i = curs[i]
            if r_i - p_i > 1:
                q_i = rand_part(L, p_i, r_i - 1)
                any_sorted = True
                if p_i < q_i < r_i:
                    curs.insert(i, q_i)
                    break
                elif q_i == r_i:
                    curs.insert(i, q_i - 1)
                    break
                elif q_i == p_i:
                    curs.insert(i, p_i + 1)
                    break
            i += 1
