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
int partition(int *array, int l, int r, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[r];
	i = l;
	j = r;

	while (i < j)
	{
		if (array[i] == array[j])
		{
			i++;
			j--;
		}
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}

	temp = array[j];
	array[j] = array[l];
	array[l] = temp;
	print_array(array, size);

	return (j);
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

	if (l < r)
	{
		j = partition(A, l, r, size);

		quicksort(A, l, j, size);
		quicksort(A, j + 1, r, size);
	}
}

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
