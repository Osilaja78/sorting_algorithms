#include "sort.h"
#include <stdbool.h>

/**
 * swap_nodes - swaps two nodes.
 * @list: pointer to the head of the list
 * @node1: node 1
 * @node2: node 2
 *
 * Return: nothing.
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp = node1->next;

	node1->next = node2->next;
	node2->next = temp;

	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->next != NULL)
		node2->next->prev = node2;

	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;

	if (node1->prev != NULL)
		node1->prev->next = node1;
	else
		*list = node1;
	if (node2->prev != NULL)
		node2->prev->next = node2;
	else
		*list = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list using
 * cocktail sort algorithm.
 * @list: list to sort
 *
 * Return: nothing.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	bool swapped = true;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = false;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = true;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (swapped == false)
			break;
		swapped = false;

		current = current->prev;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = true;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
