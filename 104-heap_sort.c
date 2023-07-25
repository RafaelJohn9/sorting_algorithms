#include "sort.h"

/**
 * print_heap - Prints an array representing a heap.
 *
 * @array: The array to be printed.
 * @size: The size of the array.
 */
void print_heap(const int *array, size_t size)
{
	size_t i;
	
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * sift_down - Repairs the heap whose root element is at index 'start'.
 *             When finished, the heap is a sorted array in ascending order.
 *
 * @array: The array to be sorted.
 * @start: The index of the root element.
 * @end: The index of the last element in the array.
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	size_t swap;
	
	while ((2 * root + 1) <= end)
	{
		child = 2 * root + 1;
		swap = root;
		
		if (array[swap] < array[child])
			swap = child;
		
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		
		if (swap != root)
		{
			int temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_heap(array, size);
			root = swap;
		}
		else
		{
			return;
		}
	}
}
/**
 * heapify - Converts an array into a max heap.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	int i;
	
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	
	heapify(array, size);
	
	for (end = size - 1; end > 0; end--)
	{
		int temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		print_heap(array, size);
		sift_down(array, 0, end - 1, size);
	}
}
