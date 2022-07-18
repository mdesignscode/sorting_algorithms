#include "sort.h"

/**
 * add_dnode - add a node to the right place in a
 * doubly linked list.
 * @list: the list to be added to.
 * @change: the node to be inserted.
 *
 * Return: nothing.
 */
void add_dnode(listint_t **list, listint_t **change)
{
	listint_t *temp, *current;

	temp = *list;
	current = *change;

	if (current->next)
		current->next->prev = current->prev;
	current->prev->next = current->next;

	current->prev = temp->prev;
	current->next = temp;

	temp->prev->next = current;
	temp->prev = current;
}

/**
 * add_front - inserts a doubly linked node in the beginning of a list.
 * @list: the list to be added to.
 * @node: the node to be inserted.
 *
 * Return: nothing.
 */
void add_front(listint_t **list, listint_t *node)
{
	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	node->next = *list;
	node->prev = NULL;
	(*list)->prev = node;
	*list = node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: the list to be sorted.
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *next;
	char flag = 0;

	if (!*list || !(*list)->next)
		return;

	current = *list;

	while (current)
	{
		temp = current->prev;
		next = current->next;

		while (temp)
		{
			if (flag)
			{
				print_list(*list);
				flag = 0;
			}
			if (!temp->prev && temp->n > current->n)
			{
				add_front(list, current);
				flag = 1;
			}

			if (temp->prev)
			{
				if ((temp->prev->n < current->n) && (temp->n > current->n))
				{
					add_dnode(&temp, &current);
					flag = 1;
				}
			}

			temp = temp->prev;
		}
		current = next;
	}

}
