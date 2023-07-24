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
 * shell_sort -  sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the
 * Knuth sequence
 * @array: array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: nothing.
*/
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	if (array == NULL || size <= 1)
		return;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
		
}
