#include "sort.h"

/**
 * heapify - builds a max heap.
 * @array: the array to be sorted.
 * @size: the size of the array.
 * @i: the index of the current node.
 * @unsorted: the size of the unsorted array.
 *
 * Return: nothing.
 */
void heapify(int *array, size_t size, int i, size_t unsorted)
{
	int max, left, right;
	int temp;

	max = i;
	left = (2 * i) + 1;
	right = (2 * i) + 2;

	if (right < (int)unsorted && array[right] > array[i])
		max = right;

	if (left < (int)unsorted && array[left] > array[max])
		max = left;

	if (i != max)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;

		print_array(array, size);

		heapify(array, size, max, unsorted);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Return: nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;
	size_t c = size - 1;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);

		heapify(array, size, 0, c--);
	}
}
