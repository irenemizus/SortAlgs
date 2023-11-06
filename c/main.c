#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

    // QuickSortRecursive
    uint32_t* L_rec = make_rand_list(len);

    printf("Initial list for QuickSortRecursive: ");
    print_list(L_rec, len);

    size_t s = 3;
    uint32_t Ls = rand_select(L_rec, 0, len - 1, s);
    printf("The %d-th element of the list: %d\n", s, Ls);

    QuickSortRecursive(L_rec, 0, len - 1);
    printf("Sorted list for QuickSortRecursive: ");
    print_list(L_rec, len);

    free(L_rec);

    // MergeSort
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

    // MergeSortRecursive
    uint32_t* IN_rec = make_rand_list(len);
    printf("\nInitial list for MergeSortRecursive: ");
    print_list(IN_rec, len);


    size_t p_rec = 0;
    size_t r_rec = len;

    MergeSortRecursive(IN_rec, len, p_rec, r_rec, NULL);
    printf("MergeRecursive-sorted list: ");
    print_list(IN_rec, len);

    free(IN_rec);

    // Getting performance statistics
    printf("\nLength\tT_qsr\tT_ms\tT_msr\n");
    double step = pow(2.0, 1.0 / 5);
    for (double len_L_d = 8; len_L_d < 10000000; len_L_d=len_L_d * step) {
        size_t len_L = (size_t)len_L_d;
        printf("%zu\t", len_L); fflush(stdout); // Length of the array

        // Generating an array of the given length
        uint32_t* L_init = make_rand_list(len_L);

        // Making copies of L_init for the algorithms in comparison:
        // QuickSortRecursive
        uint32_t* L_qsr = (uint32_t*)malloc(len_L * sizeof(L_init[0]));
        memcpy((void*)L_qsr, (void*)L_init, len_L * sizeof(L_init[0]));
        // MergeSort
        uint32_t* L_ms = (uint32_t*)malloc(len_L * sizeof(L_init[0]));
        memcpy((void*)L_ms, (void*)L_init, len_L * sizeof(L_init[0]));
        // MergeSortRecursive
        uint32_t* L_msr = (uint32_t*)malloc(len_L * sizeof(L_init[0]));
        memcpy((void*)L_msr, (void*)L_init, len_L * sizeof(L_init[0]));

        // Measuring time performance for the algorithms in comparison:
        // QuickSortRecursive
        clock_t sec_i_qsr = clock();
        QuickSortRecursive(L_qsr, 0, len_L - 1);
        //printf("sdepth: %d\t", sdepth_max); fflush(stdout);
        //sdepth_max = 0;
        clock_t sec_f_qsr = clock();

        double time_qsr = ((double)(sec_f_qsr - sec_i_qsr) / CLOCKS_PER_SEC);
        printf("%f\t", time_qsr); fflush(stdout);

        // MergeSort
        clock_t sec_i_ms = clock();
        MergeSort(L_ms, len_L, 0, len_L);
        clock_t sec_f_ms = clock();

        double time_ms = ((double)(sec_f_ms - sec_i_ms) / CLOCKS_PER_SEC);
        printf("%f\t", time_ms); fflush(stdout);

        // MergeSortRecursive
        clock_t sec_i_msr = clock();
        MergeSortRecursive(L_msr, len_L, 0, len_L, NULL);
        clock_t sec_f_msr = clock();

        double time_msr = ((double)(sec_f_msr - sec_i_msr) / CLOCKS_PER_SEC);
        printf("%f", time_msr); fflush(stdout);

        printf("\n");

        free(L_init);
        free(L_qsr);
        free(L_ms);
        free(L_msr);
    }

    return 0;
}
