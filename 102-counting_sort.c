#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers using
 * counting sort algorithm.
 * @arary: array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: nothing.
*/
void counting_sort(int *array, size_t size)
{
        int j, max, *counting_array, *sorted_array;
        size_t i;
        __ssize_t k;

        if (array == NULL || size <= 1)
                return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	counting_array = malloc(sizeof(int) * (max + 1));
	if (counting_array == NULL)
		return;

	for (j = 0; j <= max; j++)
		counting_array[j] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (j = 1; j <= max; j++)
		counting_array[j] += counting_array[j - 1];
        print_array(counting_array, max + 1);

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
                return;

	for (k = size - 1; k >= 0; k--)
	{
		sorted_array[counting_array[array[k]] - 1] = array[k];
		counting_array[array[k]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(counting_array);
	free(sorted_array);
}
