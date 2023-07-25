nclude "sort.h"

void mergesot(int *array, int *barry, int low, int mid, int upp);

/**
 * recmerge - recursive merge
 * @array: the array to sort
 * @barry: the sorted sub array
 * @low: the lower bound
 * @upp: the upper bound
 */

void recmerge(int *array, int *barry, int low, int upp)
{
	int mid;

	if (low < upp)
	{
		mid = (low + upp) / 2;
		recmerge(array, barry, low, mid);
		recmerge(array, barry, mid + 1, upp);
		mergesot(array, barry, low, mid, upp);
	}
}

/**
 * mergesot - divide the array into subarrays
 * @array: the array to sort
 * @barry: the subarray
 * @low: the lower bound
 * @upp: the upper bound
 * @mid: the halfway point
 */

void mergesot(int *array, int *barry, int low, int mid, int upp)
{
	int i = low, j = mid + 1, k = low;

	while (i <= mid && j <= upp)
	{
		if (array[i] <= array[j])
		{
			barry[k] = array[i];
			i++;
		}
		else
		{
			barry[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= upp)
		{
			barry[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			barry[k] = array[i];
			i++;
			k++;
		}
	}
	for (k = low; k <= upp; k++)
		array[k] = barry[k];

	printf("Merging...\n[left]: ");
	print_array(barry + low, mid - low);
	printf("[right]: ");
	print_array(barry + mid, upp - mid);
	printf("[Done]: ");
	print_array(barry + low, upp - low);
}

/**
 * merge_sort - driver function to sort an array
 * @array: the array to be sorted
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *barry;

	if (array == NULL || size < 2)
		return;

	barry = malloc(sizeof(int) * size);
	if (!barry)
		return;
	recmerge(array, barry, 0, size);

	free(barry);
}
