#include "sort.h"

/**
 * bubble_sort-this is a bubble sort algorithm
 * @array: array being sorted
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swaps = 0;
	int temp, i, j;

	if (size == 1 || size == 0 || !array)
	{
		return;
	}
	for (i = (size - 1); i > 0; i--)
	{
		swaps = 0;
		for (j = 0; j <= i; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array((const int *)array, size);
				swaps++;
			}
		}
		if (swaps == 0)
		{
			break;
		}
	}
}
