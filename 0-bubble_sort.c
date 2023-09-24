#include "sort.h"

/**
 * bubble_sort - sorts array in ascending order
 * @array: array of integers
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	int change;
	int tmp;
	size_t a, b;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		change = 0;

		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				change = 1;
				print_array(array, size);
			}
		}
		if (change == 0)
			break;
	}
}
