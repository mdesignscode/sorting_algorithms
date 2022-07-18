#include "sort.h"

/**
 * partition - partitions a list.
 * @array: the array to be sorted.
 * @l: lower bound.
 * @r: upper bound.
 * @size: size of array.
 *
 * Return: the correct.
 */
size_t partition(int *array, int l, int r, size_t size)
{
	int i, j, pivot, temp;

	pivot = r;
	i = l - 1;

	for (j = l; j < pivot; j++)
	{
		if (array[j] < array[pivot])
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}

	}
	i++;
	temp = array[i];
	array[i] = array[pivot];
	array[pivot] = temp;
	print_array(array, size);

	return (i);
}

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

	if (l >= r)
		return;

	j = partition(A, l, r, size);

	quicksort(A, l, j - 1, size);
	quicksort(A, j + 1, r, size);
}


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
