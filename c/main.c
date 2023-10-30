#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort_algs.h"


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


int main() {

    size_t len = 12;
    uint32_t* L = make_rand_list(len);

    printf("Initial list for QuickSort: ");
    print_list(L, len);

    size_t s = 3;
    uint32_t Ls = rand_select(L, 0, len - 1, s);
    printf("The %d-th element of the list: %d\n", s, Ls);

    L = QuickSort(L, 0, len - 1);
    printf("Sorted list for QuickSort: ");
    print_list(L, len);

    free(L);

    //uint32_t IN[] = { 60, 33, 16, 99, 78, 35, 97, 26, 12, 67, 10, 12 };
    uint32_t* IN = make_rand_list(len);
    printf("\nInitial list for MergeSort: ");
    print_list(IN, len);


    size_t p = 3;
    size_t r = 8;

    MergeSort(IN, len, p, r);
    printf("Merge-sorted list: ");
    print_list(IN, len);

    free(IN);

    return 0;
}
