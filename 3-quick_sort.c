#include <stdio.h>
#include "sort.h"

/**
 * swap - Function to swap two integers
 * @a: first num
 * @b: second num
 **/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition- scheme of lomuto partition
 * @array: array of int
 * @low: low
 * @high: high
 * @size: size of array
 * Return: the partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_helper- recursive function
 * @array:array of int
 * @low: low
 * @high: high
 * @size: size of array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pivot_idx - 1, size);
		quick_sort_helper(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort-function that sorts using the algo
 * @array: the array of int
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_helper(array, 0, size - 1, size);
}
