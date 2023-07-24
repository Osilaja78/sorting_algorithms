#include "sort.h"
#include <stdbool.h>

/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: pointer to array to be sorted
 * @size: size of array to be sorted
 *
 * Return: nothing.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;
	bool swap;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		swap = false;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				swap = true;
			}
		}
		if (swap == true)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
