#include "sort.h"

/**
 * insertion_sort_list - sorts list of integers in ascending order
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *crnt, *prev, *tmp;

	if (*list == NULL || list == NULL || (*list)->next)
		return;

	crnt = (*list)->next;
	while (crnt != NULL)
	{
		prev = crnt->prev;
		tmp = crnt->next;

		while (prev != NULL && prev->n > crnt->n)
		{
			prev->next = crnt->next;
			if (crnt->next != NULL)
				crnt->next->prev = prev;
			crnt->prev = prev->prev;
			crnt->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = crnt;
			else
				*list = crnt;
			prev->prev = crnt;
			print_list(*list);
			prev = crnt->prev;
		}
		crnt = tmp;
	}
}
