#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm, using Hoare's Partitioning Method
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
