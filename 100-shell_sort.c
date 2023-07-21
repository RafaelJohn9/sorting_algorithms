#include "sort.h"

/**
 * shell_sort-sorts using shell algorithm
 * @array: arr of int
 * @size: size of arr
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int tmp;

	while (gap < size)
		gap = gap * 3 + 1;

	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
