#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	char flag = 0;

	if (!array || !size || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (flag)
			{
				print_array(array, size);
				flag = 0;
			}
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
		}
	}
}
