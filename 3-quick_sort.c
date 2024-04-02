#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
