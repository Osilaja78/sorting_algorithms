#include <stdbool.h>
#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array using bubble sort algo.
 * @array: array to be sorted.
 * @size: size of the array to be sorted.
 *
 * Return: nothing.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - 1 - i; j++)
	{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}

		if (swapped == false)
			break;
	}
}
