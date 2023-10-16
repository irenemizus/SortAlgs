#include <stdio.h>
#include <stdlib.h>

void print_list(uint32_t* L, size_t len) {
    printf("[");

    if (len > 0) {
        for (size_t i = 0; i < len - 1; i++) {
            printf("%d, ", L[i]);
        }
        printf("%d]\n", L[len - 1]);
    }
    else {
        printf("]");
    }
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
    float v01 = (float)rand() / RAND_MAX;
    v01 *= (float)(r - p);
    size_t piv_ind = (size_t)(v01 + (float)p);
    uint32_t tmp = L[r];
    L[r] = L[piv_ind];
    L[piv_ind] = tmp;
    return part(L, p, r);
}

uint32_t* QuickSort(uint32_t* L, size_t p, size_t r) {
    if (p < r) {
        size_t q = rand_part(L, p, r);
        if (q > 0) QuickSort(L, p, q - 1);
        QuickSort(L, q + 1, r);
    }
    return L;
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
}

int main() {
    size_t len = 10;
    uint32_t *L = (uint32_t*)malloc(len * sizeof(uint32_t));
    for (size_t i = 0; i < len; i++) {
        uint32_t v = rand();
        L[i] = v;
    }
    printf("Initial list: ");
    print_list(L, len);

    size_t s = 3;
    uint32_t Ls = rand_select(L, 0, len - 1, s);
    printf("The %d-th element of the list: %d\n", s, Ls);

    L = QuickSort(L, 0, len - 1);
    printf("Sorted list: ");
    print_list(L, len);

    free(L);
    return 0;
}
