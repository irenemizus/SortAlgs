#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sort_algs.h"

#include "third_party/cutest-1.5/CuTest.h"


static size_t len_L;

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

void TestIsSortedQuickSortRecursive(CuTest* tc) {
    uint32_t *L = make_rand_list(len_L);
    QuickSortRecursive(L, 0, len_L - 1);
    CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
}

void TestIsSortedMergeSort(CuTest* tc) {
    uint32_t *L = make_rand_list(len_L);
    MergeSort(L, len_L, 0, len_L);
    CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
}

void TestIsSortedMergeSortRecursive(CuTest* tc) {
    uint32_t *L = make_rand_list(len_L);
    MergeSortRecursive(L, len_L, 0, len_L, NULL);
    CuAssertTrue(tc, IsSorted(L, len_L) == TRUE);
}

/*-------------------------------------------------------------------------*
 * main
 *-------------------------------------------------------------------------*/

CuSuite* CuGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();

    len_L = 123;
    srand(0);

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
