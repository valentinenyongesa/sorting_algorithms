#include "sort.h"

/**
 * selection_sort - Sorts array of integers using selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b, small_index;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		small_index = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[small_index])
				small_index = b;
		}
		if (small_index != a)
		{
			tmp = array[a];
			array[a] = array[small_index];
			array[small_index] = tmp;
			print_array(array, size);
		}
	}
}
