#include "sort.h"

int *originalArray;
size_t originalSize;
void print_it(void);

/**
 * quick_sort_helper- sorts an array of integers in ascending order using the algorithm
 * @array:to  be sorted
 * @size:size of the array
 * @originalSize: original size of the array
 */
void quick_sort_helper(int *array, size_t size)
{
	int *left, *right;
	int i, lastNumIndex = (int)size - 1, temp, pivot, low;
	size_t sizeOfRight,  sizeOfLeft;

	if (!array || size  == 1 || size == 0)
	{
		return;
	}
	pivot = array[lastNumIndex];
	low = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] >  pivot && i < lastNumIndex)
		{
			temp = array[lastNumIndex];
			array[lastNumIndex] = array[i];
			array[i] = temp;
			lastNumIndex = i;
			print_it();
		}
		else if (array[i] <=  array[lastNumIndex] && i > lastNumIndex)
		{
			temp = array[lastNumIndex];
			array[lastNumIndex] = array[i];
			array[i] = temp;
			lastNumIndex = i;
			i = low - 1;
			print_it();

		}
	}
	left = array;
	sizeOfLeft = lastNumIndex;
	right = &array[lastNumIndex + 1];
	sizeOfRight = size - (lastNumIndex + 1);
	quick_sort_helper(left, sizeOfLeft);
	quick_sort_helper(right, sizeOfRight);
}

void print_it(void)
{
	print_array(originalArray, originalSize);
}
	
/**
 * quick_sort- sorts an array of integers in ascending order using the algorithm
 * @array:to  be sorted
 * @size:size of the array
 */
void quick_sort(int *array, size_t size)
{
	originalArray = array;
	originalSize = size;
	quick_sort_helper(array, size);
}
