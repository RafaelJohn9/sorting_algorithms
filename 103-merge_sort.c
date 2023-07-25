#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @left: Pointer to the left subarray.
 * @right: Pointer to the right subarray.
 */
void merge(int *array, size_t size, int *left, int *right)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;
	
	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j]) 
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	
	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	size_t left_size = mid, i;
	size_t right_size = size - mid;
	int *left = malloc(left_size * sizeof(int));
	int *right = malloc(right_size * sizeof(int));
	
	if (size < 2)
		return;
	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];
	
	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, size, left, right);
	
	free(left);
	free(right);
}
