#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 * @pos: significant bit to sort.
 *
 * Return: nothing.
 */
void counting_sort2(int *array, size_t size, size_t pos)
{
	int *new_array, count_array[10] = {0};
	size_t i, k = 0;

	new_array = malloc(sizeof(int) * size);
	if (!new_array)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > (int)k)
			k = array[i];

	for (i = 0; i < size; i++)
		++count_array[(array[i]/pos) % 10];

	for (i = 1; i <= 9; i++)
		count_array[i] = count_array[i] + count_array[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
		new_array[--count_array[(array[i]/pos) % 10]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = new_array[i];

	free(new_array);
	new_array = NULL;
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, pos;
	size_t i;

	if (!array || !size || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (pos = 1; (max / pos) > 0; pos *= 10)
	{
		counting_sort2(array, size, pos);
		print_array(array, size);
	}
}
