#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left = NULL;
	listint_t *right = NULL;
	
	if (!list || !(*list) || !(*list)->next)
		return;
	
	do
	{
		swapped = 0;
		for (left = *list; left->next != right; left = left->next)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		right = left;
		
		for (right = right->prev; right && right->prev != left; right = right->prev)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{

	if (!node1 || !node2)
		return;
	
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;
	
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
        node2->next = node1;
}
