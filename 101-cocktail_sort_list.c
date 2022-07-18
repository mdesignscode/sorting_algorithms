#include "sort.h"

/**
 * swap_nodes - swaps two nodes.
 * @node1: node 1.
 * @node2: node 2.
 *
 * Return: nothing.
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;

	node1->prev = node1->next;
	node1->next = node2->next;

	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: the list to be sorted.
 *
 * Return: nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *first, *next, *current;

	if (!*list || !(*list)->next)
		return;

	current = *list;

	while (current)
	{
		first = current;
		while (first->next)
		{
			next = first->next;
			if (first->n < next->n)
				first = first->next;

			else
			{
				swap_nodes(first, next);
				print_list(*list);
			}
		}

		while (first->prev)
		{
			next = first->prev;
			if (first->n > next->n)
				first = first->prev;

			else
			{
				swap_nodes(next, first);
				if (!first->prev)
					*list = first;
				print_list(*list);
			}
		}

		current = current->next;
	}
}
