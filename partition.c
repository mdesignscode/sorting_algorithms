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
