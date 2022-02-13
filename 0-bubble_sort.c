#include "sort.h"
/**
 *  bubble_sort - sort an array using Bubble sort
 *
 * @array: array to sort
 * @size: long array
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx = 0;
	int value;

	if (array)
	{
		while (1)
		{
			for (idx = 0; idx < size; idx++)
			{
				if (array[idx - 1] > array[idx])
				{
					value = array[idx - 1];
					array[idx - 1] = array[idx];
					array[idx] = value;
					print_array(array, size);
				}
			}
			if (check_sort(array, size) == 0)
				break;
		}
	}
}

/**
 *  check_sort - check if an array is sorted
 *
 * @array: array to sort
 * @size: long array
 * Return: 0 is sorted or 1 not is sorted
 */
int check_sort(const int *array, size_t size)
{
	size_t idx = 0;

	for (idx = 0; idx < size; idx++)
	{
		if (array[idx - 1] > array[idx])
		{
			return (1);
		}
	}
	return (0);
}
