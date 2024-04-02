#include "sort.h"

/**
 * test_algorithm - tests a sorting algorithm
 * @original_list: the list to be sorted
 * @expected_list: a sorted list to be compared to
 * @n: the length of the list
 * @test_case: the test case
 *
 * Return: nothing.
 */
void test_algorithm(int *original_list, int *expected_list, size_t n, char *test_case)
{
  int case_passed = 1;
  size_t i = 0;

  for (; i < n; i++)
  {
    if (original_list[i] != expected_list[i])
    {
      case_passed = 0;
      break;
    }
  }

  i = 0;

  printf("%s: %s\n", test_case, !case_passed ? "failed" : "passed");
}

/**
 * test_different_cases - tests a sorting algorithm
 * @algorithm: a pointer to the algorithm to be tested
 *
 * Return: nothing.
 */
void test_different_cases(void (*algorithm)(int *array, size_t size), char *algorithm_name)
{
  /* case 1 */
  int unsorted_list[] = {4, 6, 2, 1, 8, 5, 7, 3, 9, 10};
  int sorted_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t n = sizeof(unsorted_list) / sizeof(unsorted_list[0]);

  /* case 2 */
  int duplicate_list[] = {2, 3, 8, 2, 2, 5};
  int sorted_duplicate_list[] = {2, 2, 2, 3, 5, 8};
  size_t n2 = sizeof(duplicate_list) / sizeof(duplicate_list[0]);

  /* case 3 */
  int one_item[] = {2};
  int sorted_one_item[] = {2};
  size_t n3 = sizeof(one_item) / sizeof(one_item[0]);

  algorithm(unsorted_list, n);
  algorithm(duplicate_list, n2);
  algorithm(one_item, n3);

  printf("\n\n--------------------------------------------------\n");
  printf("Test results for %s sort:\n", algorithm_name);

  test_algorithm(unsorted_list, sorted_list, n, "Sorted in ascending order");
  test_algorithm(duplicate_list, sorted_duplicate_list, n2, "Sorted duplicate items");
  test_algorithm(one_item, sorted_one_item, n3, "Doesn't sort a list with one item or less");

  printf("--------------------------------------------------\n");
}

/**
 * main - tests a list of sorting algorithms.
 *
 * Return: 0.
 */
int main()
{
  test_different_cases(bubble_sort, "Bubble");
  printf("\n\n");
  test_different_cases(selection_sort, "Selection");
  printf("\n\n");
  test_different_cases(quick_sort, "Quick");
  printf("\n\n");
  test_different_cases(shell_sort, "Shell");
  printf("\n\n");
  test_different_cases(quick_sort_hoare, "Hoare Quick");
  printf("\n\n");
  test_different_cases(counting_sort, "Counting");
  printf("\n\n");
  test_different_cases(merge_sort, "Merge");
  printf("\n\n");
  test_different_cases(heap_sort, "Heap");
  printf("\n\n");
  test_different_cases(radix_sort, "Radix");
  printf("\n\n");
  test_different_cases(bitonic_sort, "Bitonic");

  return (0);
}
