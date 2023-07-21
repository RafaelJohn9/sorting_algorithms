#include "sort.h"

/**
 * quick_sort_helper- sorts an array of integers in ascending order using the algorithm
 * @array:to  be sorted
 * @size:size of the array
 * @originalSize: original size of the array
 */
void quick_sort_helper(int *array, size_t size, size_t originalSize)
{
	static size_t sizeOfOriginal;
	int *left, *right;
	int i, lastNumIndex = (int)size - 1, temp, pivot, low;
	size_t sizeOfRight,  sizeOfLeft;

	if (!array || size  == 1 || size == 0)
	{
		return;
	}
	pivot = array[lastNumIndex];
	low = 0;
	sizeOfOriginal = originalSize;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] >  pivot && i < lastNumIndex)
		{
			temp = array[lastNumIndex];
			array[lastNumIndex] = array[i];
			array[i] = temp;
			lastNumIndex = i;
			print_array(array, sizeOfOrginal);
		}
		else if (array[i] <=  array[lastNumIndex] && i > lastNumIndex)
		{
			temp = array[lastNumIndex];
			array[lastNumIndex] = array[i];
			array[i] = temp;
			lastNumIndex = i;
			i = low - 1;
			print_array(array, sizeOfOriginal);
		}
	}
	left = array;
	sizeOfLeft = lastNumIndex;
	right = &array[lastNumIndex + 1];
	sizeOfRight = size - (lastNumIndex + 1);
	quick_sort(left, sizeOfLeft);
	quick_sort(right, sizeOfRight);
}


/**
 * quick_sort- sorts an array of integers in ascending order using the algorithm
 * @array:to  be sorted
 * @size:size of the array
 */
void quick_sort_helper(int *array, size_t size, size_t originalSize)
{
	 quick_sort_helper(array, size, size);
}
