#include "stdio.h"

/**
 * print_portion - prints a portion of an array.
 * @array: the array to be printed.
 * @left: lower bound.
 * @right: upper bound.
 *
 * Return: nothing.
 */
void print_portion(int *array, int left, int right)
{
  int i;

  for (i = left; i <= right; i++)
  {
    printf("%d", array[i]);

    if (i < right)
    {
      putchar(',');
      putchar(' ');
    }
  }
  putchar('\n');
}
