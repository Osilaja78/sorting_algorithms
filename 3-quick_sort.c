#include "sort.h"

/**
 * swap - swaps two elements.
 * @a: element a
 * @b: element b
 * 
 * Return: nothing.
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitons a sub-array using lomuto partition scheme.
 * @array: array to be partitioned
 * @low: low index
 * @high: high index
 * 
 * Return: index of the partition.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort_function - quick sort function helper.
 * @array: array to be partitioned
 * @low: low index
 * @high: high index
 *
 * Return: nothing.
*/
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using quick sort algorithm.
 * @array: array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: nothing.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
