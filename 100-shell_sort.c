#include "sort.h"

/**
 * shell_sort - Sort array using shell sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t space = 1, a, b;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;

	while (space >= 1)
	{
		print_array(array, size);

		for (a = space; a < size; a++)
		{
			tmp = array[a];
			b = a;

			while (b >= space && array[b - space] > tmp)
			{
				array[b] = array[b - space];
				b -= space;
			}

			array[b] = tmp;
		}
		space /= 3;
	}
	print_array(array, size);
}
