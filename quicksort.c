#include "sort.h"

/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @A: array to be sorted.
 * @l: lower bound.
 * @r: upper bound.
 * @size: size of array.
 *
 * Return: nothing.
 */
void quicksort(int *A, int l, int r, size_t size)
{
  int j;

  if (l < r)
  {
    j = partition(A, l, r, size);

    quicksort(A, l, j, size);
    quicksort(A, j + 1, r, size);
  }
}
