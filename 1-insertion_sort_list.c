#include "sort.h"
/**
 *  insertion_sort_list - function that sorts a doubly linked list of
 * integers in
 * ascending order using the Insertion sort
 *
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node_exit = NULL, *node_tmp = NULL, *node_two = NULL;
	listint_t *node_next = NULL, *node_rec = NULL, *new_head = NULL;

	if (list && *list)
	{
		node_rec = *list;
		while (node_rec->next)
		{
			new_head = NULL, node_exit = NULL, node_next = NULL;
			node_tmp = NULL, new_head = NULL;

			if (node_rec->n > node_rec->next->n)
			{
				node_tmp = node_rec;
				node_exit = node_tmp->next ? node_tmp->next : NULL;
				if (!node_tmp->prev)
				{
					node_two = NULL;
					new_head = node_exit;
				}
				else
					node_two = node_tmp->prev;
				node_next = node_exit->next ? node_exit->next : NULL;
				if (node_two)
					node_two->next = node_exit; /*48 al 71*/
				node_exit->prev = node_two ? node_two : NULL;  /*el 71 al 48*/
				node_exit->next = node_tmp;					   /*71 al 99*/
				node_tmp->prev = node_exit;					   /*99 al 71*/
				node_tmp->next = node_next ? node_next : NULL; /*99 al 13*/
				node_rec = node_rec->prev;

				if (node_next)
					node_next->prev = node_tmp;
				*list = new_head ? new_head : *list;
				print_list(*list);
			}
			riverse_list(node_exit, node_two, new_head, node_tmp, list);
			node_rec = node_rec->next ? node_rec->next : NULL;
		}
	}
}

/**
 * riverse_list - function that sorts a doubly linked list of
 * @node_exit: ::::::::::::::
 * @node_two: ::::::::::::::
 * @new_head: :::::::::::::::
 * @node_tmp: ::::::::::::::::::
 * @list: doubly linked list
 */
void riverse_list(listint_t *node_exit, listint_t *node_two,
listint_t *new_head, listint_t *node_tmp, listint_t **list)
{
	while ((node_exit && node_two) && (node_exit->n < node_two->n))
	{
		if (node_two->prev)
			node_two->prev->next = node_exit;

		node_exit->prev = node_two->prev ? node_two->prev : NULL;
		if (node_two->prev)
		{
			node_two->prev = node_exit;
		}
		else
		{
			new_head = node_exit;
			node_two->prev = node_exit;
			node_exit->prev = NULL;
		}

		node_two->next = node_tmp;
		node_tmp->prev = node_two;
		node_exit->next = node_two;
		node_tmp = node_two;
		if (node_tmp->prev)
			node_two = node_tmp->prev->prev;
		*list = new_head ? new_head : *list;
		print_list(*list);
	}
}
