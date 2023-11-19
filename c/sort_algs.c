#include "indx_list.h"
#include "sort_algs.h"

#include <stdlib.h>
#include <string.h>

#ifndef BOOL
#define BOOL int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

uint32_t* make_rand_list(size_t len, size_t max_rand_val) {
    uint32_t *L = (uint32_t*)malloc(len * sizeof(uint32_t));
    for (size_t i = 0; i < len; i++) {
        uint32_t v = rand() % max_rand_val;
        L[i] = v;
    }
    return L;
}

size_t part(uint32_t* L, size_t p, size_t r) {
    uint32_t piv = L[r];
    size_t i = p - 1;
    for (size_t j = p; j < r; j++) {
        if (L[j] <= piv) {
            i++;
            uint32_t tmp = L[j];
            L[j] = L[i];
            L[i] = tmp;
        }
    }
    L[r] = L[i + 1];
    L[i + 1] = piv;
    return i + 1;
}

size_t rand_part(uint32_t* L, size_t p, size_t r) {
    assert (r - p < RAND_MAX);
    size_t piv_ind = rand() % (r - p + 1) + p;
    //float v01 = (float)rand() / RAND_MAX;
    //v01 *= (float)(r - p);
    //size_t piv_ind = (size_t)(v01 + (float)p);
    uint32_t tmp = L[r];
    L[r] = L[piv_ind];
    L[piv_ind] = tmp;
    return part(L, p, r);
}

void QuickSortRecursive(uint32_t* L, size_t p, size_t r) {
    if (p < r) {
        size_t q = rand_part(L, p, r);
        if (q > 0) QuickSortRecursive(L, p, q - 1);
        QuickSortRecursive(L, q + 1, r);
    }
}

void QuickSort(uint32_t* L, size_t p, size_t r) {
    struct indx_item* indx = indx_create_initial(p);
    struct indx_item* indx_first = indx; // Points to the first list in the indx list
    indx_create_next(indx, r + 1);
    BOOL any_sorted = TRUE;

    indx = indx_first;
    while (any_sorted) {
        any_sorted = FALSE;
        while (indx->next != NULL) {
            size_t p_i = indx->indx;
            size_t r_i = indx->next->indx;
            if (r_i - p_i > 1) {
                size_t q_i = rand_part(L, p_i, r_i - 1);
                any_sorted = TRUE;
                if ((p_i < q_i) && (q_i < r_i)) {
                    indx_create_next(indx, q_i);
                    break;
                } else if (q_i == r_i) {
                    indx_create_next(indx, q_i - 1);
                    break;
                } else if (q_i == p_i) {
                    indx_create_next(indx, p_i + 1);
                    break;
                }
            }
            indx = indx->next;
        }
    }
    indx_destroy_all(indx);
}

uint32_t rand_select(uint32_t* L, size_t p, size_t r, size_t s) {
    if (p == r) return L[p];
    if (p < r) {
        size_t q = rand_part(L, p, r);
        size_t k = q - p + 1;
        if (s == k) return L[q];
        else if (s < k) return rand_select(L, p, q - 1, s);
        else return rand_select(L, q + 1, r, s - k);
    }
    assert (FALSE); // Impossible case
    return -1;
}

void subarrcpy(uint32_t* OUT, size_t o1, size_t o2, uint32_t* IN, size_t i1, size_t i2) {
    assert(i2 > i1);
    assert(o2 > o1);
    assert(o2 - o1 == i2 - i1);

    memcpy((void*)&OUT[o1], (void*)&IN[i1], (i2 - i1) * sizeof(IN[0]));
}

void merge(uint32_t* IN, size_t p, size_t q, size_t r, uint32_t* OUT) {
    size_t il = p;  // Iterator left
    size_t ir = q;  // Iterator right
    size_t io = p;  // Iterator output
    while (il < q && ir < r && io < r) {
        if (IN[il] <= IN[ir]) {
            OUT[io] = IN[il];
            il++;
        } else {
            OUT[io] = IN[ir];
            ir++;
        }
        io++;
    }
    if (il < q) {       // If we haven't reached the right end of the left array yet...
        memcpy((void*)&OUT[io], (void*)&IN[il], (r - io) * sizeof(IN[0]));
    }
    if (ir < r) {       // If we haven't reached the right end of the right array yet...
        memcpy((void*)&OUT[io], (void*)&IN[ir], (r - io) * sizeof(IN[0]));
    }
}

void MergeSortRecursive(uint32_t* A, size_t len_A, size_t p, size_t r, uint32_t* A_tmp) {
    BOOL free_A_tmp = FALSE;
    if (A_tmp == NULL) {
        A_tmp = (uint32_t*)malloc(len_A * sizeof(A[0]));
        memcpy((void*)A_tmp, (void*)A, len_A * sizeof(A[0]));
        free_A_tmp = TRUE;
    }

    if ((r - p) >= 2) {
        size_t q = (r + p) / 2;
        MergeSortRecursive(A_tmp, len_A, p, q, A);
        MergeSortRecursive(A_tmp, len_A, q, r, A);
        merge(A_tmp, p, q, r, A);
    }

    if (free_A_tmp == TRUE) {
        free(A_tmp);
    }
}

void MergeSort(uint32_t* A, size_t len_A, size_t p, size_t r) {
    assert(r <= len_A);
    assert(p <= len_A);
    if (p < r && r <= len_A) {
        uint32_t* A_tmp = (uint32_t*)malloc(len_A * sizeof(A[0]));
        uint32_t* A_in = A;
        uint32_t* A_out = A_tmp;
        memcpy((void*)A_out, (void*)A, len_A * sizeof(A[0]));

        struct indx_item* indx = indx_create_initial(p);
        struct indx_item* indx_first = indx; // Points to the first list in the indx list
        size_t len_indx = 1;
        for (size_t i = p + 1; i <= r; i++) {
            indx = indx_create_next(indx, i);
            len_indx++;
        }

        struct indx_item* indx_last = indx;
        while (len_indx > 2) {
            struct indx_item* cur_indx = indx_last->prev;

            while(cur_indx != NULL && cur_indx->prev != NULL) {
                merge(A_in, cur_indx->prev->indx, cur_indx->indx, cur_indx->next->indx, A_out);
                cur_indx = cur_indx->prev->prev;
            }
            if (cur_indx != NULL) {
                // Doesn't merge anything, just copies the remaining tail
                merge(A_in, cur_indx->indx, cur_indx->indx, cur_indx->next->indx, A_out);
            }

            cur_indx = indx_last->prev;
            while(cur_indx != NULL && cur_indx->prev != NULL) {
                indx_destroy_item(cur_indx);
                cur_indx = cur_indx->prev->prev;
                len_indx--;
            }

            uint32_t* xchg_tmp = A_in;
            A_in = A_out;
            A_out = xchg_tmp;
        }

        indx_destroy_item(indx_first->next);
        indx_destroy_item(indx_first);

        memcpy((void *) A, (void *) A_in, len_A * sizeof(A[0]));
        free(A_tmp); A_tmp = NULL;
    }
}
