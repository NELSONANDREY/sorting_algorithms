#include "sort.h"
/**
 *  selection_sort - sort an array using Bubble sort
 *
 * @array: array to sort
 * @size: long array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t tmp = 0, idx;

	for (i = 0; i < size; i++)
	{
		tmp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[tmp] > array[j])
				tmp = j;
		}
		if (tmp != i)
		{
			idx = array[tmp];
			array[tmp] = array[i];
			array[i] = idx;
			print_array(array, size);
		}
	}
}
