#include "sort.h"

/**
 * merge - merge's two sorted arrays.
 * @array: first half to be sorted.
 * @left: lower bound.
 * @mid: mid point.
 * @right: upper bound.
 *
 * Return: nothing.
 */
void merge(int *array, int left, int mid, int right)
{
	int i, j, k, *temp;

	i = left;
	j = mid;
	k = left;

	temp = malloc(sizeof(int) * right + 1);
	if (!temp)
		return;

	while (i < mid && j <= right)
		temp[k++] = array[i] < array[j] ? array[i++] : array[j++];

	while (j <= right)
		temp[k++] = array[j++];
	while (i < mid)
		temp[k++] = array[i++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	free(temp);
	temp = NULL;
}

/**
 * mergesort - sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: the array to be sorted.
 * @left: lower bound.
 * @right: upper bound.
 *
 * Return: nothing.
 */
void mergesort(int *array, int left, int right)
{
	int mid;

	if (left < right)
	{
		if ((left + right) % 2)
			mid = (left + right) / 2 + 1;
		else
			mid = (left + right) / 2;

		mergesort(array, left, mid - 1);
		mergesort(array, mid, right);

		printf("Merging...\n");

		printf("[left]: ");
		print_portion(array, left, mid - 1);

		printf("[right]: ");
		print_portion(array, mid, right);

		merge(array, left, mid, right);

		printf("[Done]: ");
		print_portion(array, left, right);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void merge_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	mergesort(array, 0, size - 1);
}
