#include "sort.h"
/**
 * get_k - get the maximum element in an array
 * @array: the array
 * @size: the size of the array
 * Return: the maximum value
 */

int get_k(int *array, size_t size)
{
	int i, k = array[0];

	for (i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];
	return (k);
}

/**
 * counting_sort - sort an array of positive integers using counting sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *barry, i, k;

	if (array == NULL || size < 2)
		return;

	k = get_k(array, size);
	count = malloc(sizeof(int) * k + 1);
	if (!count)
		return;
	barry = malloc(sizeof(int) * size);
	if (!barry)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
		++count[array[i]];
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	for (i = size - 1; i >= 0; i--)
		barry[--count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = barry[i];
	free(count);
	free(barry);
}
