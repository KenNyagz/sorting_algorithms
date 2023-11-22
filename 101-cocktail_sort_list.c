#include "sort.h"

/**
*cocktail_sort_list - sorts a doubly linked list of integers (ascending)
* using the Cocktail shaker sort algorithm
*@list: the doubly linked list with the data
*
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swp_flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	start = *list;

	do {
		swp_flag = 0;
		current = *list;
		while (current  && current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swp_flag = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swp_flag)
			break;
		swp_flag = 0;
		end = current;
		while (current && current->prev != start)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev, current);
				swp_flag = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current->next;
	} while (swp_flag);
}

/**
*swap_nodes - swaps two nodes of a doubly linked list
*@list: the doubly linked list
*@node1: the first node
*@node2: the second node
*
*/

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}

	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
