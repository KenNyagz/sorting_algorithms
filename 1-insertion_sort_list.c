#include "sort.h"

/**
*insertion_sort_list - sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
*@list: doubly linked list to be sorted*
*
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;
	int key = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		key = current->n;

		while (temp != NULL && temp->n > key)
		{
			swap_nodes(list, temp, current);
			temp = current->prev;

		}
		print_list(*list);
		current = current->next;
	}
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
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
