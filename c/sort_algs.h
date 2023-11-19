//
// Created by Irene on 22/10/2023.
//

#ifndef SORT_ALGS_H
#define SORT_ALGS_H

#include "indx_list.h"

#include <stddef.h>
#include <stdint.h>

#ifndef BOOL
#define BOOL int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

uint32_t* make_rand_list(size_t len, size_t max_rand_val);

size_t part(uint32_t* L, size_t p, size_t r);

size_t rand_part(uint32_t* L, size_t p, size_t r);

void QuickSortRecursive(uint32_t* L, size_t p, size_t r);

void QuickSort(uint32_t* L, size_t p, size_t r);

uint32_t rand_select(uint32_t* L, size_t p, size_t r, size_t s);

void subarrcpy(uint32_t* OUT, size_t o1, size_t o2, uint32_t* IN, size_t i1, size_t i2);

void merge(uint32_t* IN, size_t p, size_t q, size_t r, uint32_t* OUT);

void MergeSortRecursive(uint32_t* A, size_t len_A, size_t p, size_t r, uint32_t* A_tmp);

void MergeSort(uint32_t* A, size_t len_A, size_t p, size_t r);

#endif //SORT_ALGS_H
