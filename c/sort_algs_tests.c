#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sort_algs.h"

#include "third_party/cutest-1.5/CuTest.h"


static size_t test_max = 0x7fffffff;
static size_t attempts = 100;
static size_t len_L_start = 10;

BOOL IsSorted(const uint32_t* L, size_t len_L) {
    BOOL is_sorted = TRUE;
    for (size_t i = 1; i < len_L; i++) {
        if (L[i - 1] > L[i]) {
            is_sorted = FALSE;
            break;
        }
    }
    return is_sorted;
}

BOOL ContainsSameEls(const uint32_t* L, size_t len_L, const uint32_t* L_sort) {
    uint32_t* L_tmp = (uint32_t*)malloc(len_L * sizeof(L_sort[0]));
    memcpy((void*)L_tmp, (void*)L_sort, len_L * sizeof(L_sort[0]));
    BOOL res = TRUE;
    size_t len_L_sort = len_L;
    for (size_t i = 0; i < len_L; i++) {
        BOOL found = FALSE;
        for (size_t j = 0; j < len_L_sort; j++) {
            if (L[i] == L_tmp[j]) {
                L_tmp[j] = 0xffffffff;
                found = TRUE;
                break;
            }
        }
        if (!found) { res = FALSE; goto exit; }
    }

    for (size_t i = 0; i < len_L; i++) {
        if (L_tmp[i] != 0xffffffff) { res = FALSE; goto exit; }
    }

exit:
    free(L_tmp);
    return res;
}

void TestIsSortedQuickSort(CuTest* tc) {
    for (size_t att = 0; att < attempts; att++) {
        size_t len_L = len_L_start + att;
        uint32_t *L = make_rand_list(len_L, test_max);
        uint32_t *L_init = (uint32_t *) malloc(len_L * sizeof(L[0]));
        memcpy((void *) L_init, (void *) L, len_L * sizeof(L[0]));
        QuickSort(L, 0, len_L - 1);
        CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
        CuAssertTrue(tc, ContainsSameEls(L_init, len_L, L) == TRUE);
    }
}

void TestIsSortedQuickSortRecursive(CuTest* tc) {
    for (size_t att = 0; att < attempts; att++) {
        size_t len_L = len_L_start + att;
        uint32_t *L = make_rand_list(len_L, test_max);
        uint32_t *L_init = (uint32_t *) malloc(len_L * sizeof(L[0]));
        memcpy((void *) L_init, (void *) L, len_L * sizeof(L[0]));
        QuickSortRecursive(L, 0, len_L - 1);
        CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
        CuAssertTrue(tc, ContainsSameEls(L_init, len_L, L) == TRUE);
    }
}

void TestIsSortedMergeSort(CuTest* tc) {
    for (size_t att = 0; att < attempts; att++) {
        size_t len_L = len_L_start + att;
        uint32_t *L = make_rand_list(len_L, test_max);
        uint32_t *L_init = (uint32_t *) malloc(len_L * sizeof(L[0]));
        memcpy((void *) L_init, (void *) L, len_L * sizeof(L[0]));
        MergeSort(L, len_L, 0, len_L);
        CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
        CuAssertTrue(tc, ContainsSameEls(L_init, len_L, L) == TRUE);
    }
}

void TestIsSortedMergeSortRecursive(CuTest* tc) {
    for (size_t att = 0; att < attempts; att++) {
        size_t len_L = len_L_start + att;
        uint32_t *L = make_rand_list(len_L, test_max);
        uint32_t *L_init = (uint32_t *) malloc(len_L * sizeof(L[0]));
        memcpy((void *) L_init, (void *) L, len_L * sizeof(L[0]));
        MergeSortRecursive(L, len_L, 0, len_L, NULL);
        CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
        CuAssertTrue(tc, ContainsSameEls(L_init, len_L, L) == TRUE);
    }
}

/*-------------------------------------------------------------------------*
 * main
 *-------------------------------------------------------------------------*/

CuSuite* CuGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();

    srand(0);

    SUITE_ADD_TEST(suite, TestIsSortedQuickSort);
    SUITE_ADD_TEST(suite, TestIsSortedQuickSortRecursive);
    SUITE_ADD_TEST(suite, TestIsSortedMergeSort);
    SUITE_ADD_TEST(suite, TestIsSortedMergeSortRecursive);

	return suite;
}

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, CuGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void)
{
    RunAllTests();
}
