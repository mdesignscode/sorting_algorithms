#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, temp;

	if (!array || !size || size < 2)
		return;

	gap = 1;
	while (gap <= size / 3)
		gap *= 3 + 1;

	while (gap >= 1)
	{
		for (j = gap + 1; j < size; j++)
		{
			for (i = 0; i < size; i++)
			{
				if (array[i] > array[j])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}

		gap /= 3;
		print_array(array, size);
	}

}
