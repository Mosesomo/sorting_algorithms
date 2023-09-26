#include "sort.h"

/**
 *swap_nodes - swaps the nodes of the list
 *@head: head pointer of the list
 *@n1: node1 to insert
 *@n2: node2 to insert
 */

void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 *insertion_sort_list - sort the list
 *@list: pointer to the list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		j = i->prev;
		while (j && j->n > i->n)
		{
			swap_nodes(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
