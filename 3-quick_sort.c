#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using quick sort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recur(array, 0, size - 1);
}

/**
 * quick_sort_recur - recur function for quick sort
 * @array: array to sort
 * @size: size of array
 * @l: lowest integer index
 * @h: highest integer index
 */
void quick_sort_recur(int *array, int l, int h)
{
	if (l < h)
	{
		int pvt_index = lomuto_partition(array, l, h);

		quick_sort_recur(array, l, pvt_index - 1);
		quick_sort_recur(array, pvt_index + 1, h);
	}
}

/**
 * lomuto_partition - partition for quick sort
 * @array: array to sort
 * @size: size of array
 * @l: lowest index of array
 * @h: highest index of array
 * Return: 0
 */

int lomuto_partition(int *array, int l, int h)
{
	int pvt = array[h];
	int a = l - 1;
	int b;

	for (b = l; b <= h - 1; b++)
	{
		if (array[b] < pvt)
		{
			a++;
			change(array, h + 1, a, b);
		}
	}
	change(array, h + 1, a + 1, h);
	return (a + 1);
}
/**
 * change - swaps integers
 * @array: array
 * @size: size of array
 * @i: first index element
 * @j: second element
 */
void change(int *array, size_t size, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
