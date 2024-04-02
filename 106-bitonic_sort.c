#include "sort.h"

/**
 * bitonicMerge - merges a bitonic sequence.
 * @array: the array to be sorted.
 * @left: lower bound.
 * @size: the size of the array.
 * @direction: the order of sort.
 * @r_size: size to be printed
 *
 * Return: nothing.
 */
void bitonicMerge(int *array, size_t left, size_t size, char direction, size_t r_size)
{
	size_t k, i;
	int temp;

	if (size > 1)
	{
		k = size / 2;

		for (i = left; i < left + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		bitonicMerge(array, left, k, direction, r_size);
		bitonicMerge(array, left + k, k, direction, r_size);
	}
}

/**
 * bitonicSort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: the array to be sorted.
 * @left: lower bound.
 * @size: the size of the array.
 * @direction: the order of sort.
 * @r_size: size to be printed
 *
 * Return: nothing.
 */
void bitonicSort(int *array, size_t left, size_t size, char direction, size_t r_size)
{
	size_t k;

	if (size > 1)
	{
		k = size / 2;

		if (direction)
		{
			printf("Merging [%ld/%ld] (UP):\n", size, r_size);
			print_portion(array, left, left + size - 1);
		}
		bitonicSort(array, left, k, 1, r_size);

		if (!direction)
		{
			printf("Merging [%ld/%ld] (DOWN):\n", size, r_size);
			print_portion(array, left, left + size - 1);
		}
		bitonicSort(array, left + k, k, 0, r_size);

		bitonicMerge(array, left, size, direction, r_size);
		if (direction)
		{
			printf("Result [%ld/%ld] (UP):\n", size, r_size);
			print_portion(array, left, left + size - 1);
		}
		else
		{
			printf("Result [%ld/%ld] (DOWN):\n", size, r_size);
			print_portion(array, left, left + size - 1);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	bitonicSort(array, 0, size, 1, size);
}
