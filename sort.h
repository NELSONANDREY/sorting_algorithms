#ifndef SORTING_H
#define SORTING_H
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
int check_sort(const int *array, size_t size);
int delete_node(listint_t **list, size_t idx);
void riverse_list(listint_t *node_exit, listint_t *node_two,
listint_t *new_head, listint_t *node_tmp, listint_t **list);
#endif
