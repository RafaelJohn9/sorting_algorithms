#include "sort.h"

/**
 * selection_sort- sorts an array of integers in
 *                 ascending order using the algorithm
 * @array:to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, temp, swaps = 0;
	int initialMinIndex = 0, initialMinValue;

	if (size == 1 || size == 0 || !array)
	{
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		swaps = 0;
		initialMinIndex = i;
		initialMinValue = array[i];
		for (j = i + 1; j < (int)size; j++)
		{
			if (initialMinValue > array[j])
			{
				initialMinValue = array[j];
				initialMinIndex = j;
			}
		}
		if (initialMinIndex  != i)
		{
			temp = array[i];
			array[i] = array[initialMinIndex];
			array[initialMinIndex] = temp;
			print_array((const int *)array, size);
			swaps++;
		}
	}
}
