#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array; 
	size_t index, i, max;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > (size_t)max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	
	index = 0;
	
	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[index] = i;
			index++;
			counting_array[i]--;
		}
	}
	print_array(counting_array, max + 1);
	free(counting_array);
}
