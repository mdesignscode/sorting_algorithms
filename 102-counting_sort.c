#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *new_array, *count_array;
	size_t i, k = 0;

	if (!array || !size || size < 2)
		return;

	new_array = malloc(sizeof(int) * size);
	if (!new_array)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > (int)k)
			k = array[i];

	count_array = malloc(sizeof(int) * k + 1);
	if (!count_array)
		return;

	memset(count_array, 0, sizeof(int) * k + 1);

	for (i = 0; i < size; i++)
		++count_array[array[i]];

	for (i = 1; i <= k; i++)
		count_array[i] = count_array[i] + count_array[i - 1];

	print_array(count_array, k + 1);

	for (i = size - 1; (int)i >= 0; i--)
		new_array[--count_array[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = new_array[i];

	free(count_array);
	count_array = NULL;
	free(new_array);
	new_array = NULL;
}
