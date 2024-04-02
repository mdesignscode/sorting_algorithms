#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	int cur_min, new_min, temp;
	size_t i, j;

	if (!array || !size || size < 2)
		return;

	cur_min = new_min = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[cur_min] && array[j] < array[new_min])
				new_min = j;
		}
		if (array[cur_min] > array[new_min])
		{
			temp = array[cur_min];
			array[cur_min] = array[new_min];
			array[new_min] = temp;

			print_array(array, size);
		}
		cur_min = i + 1;
		new_min = i + 1;
	}
}
