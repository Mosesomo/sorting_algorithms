#include "sort.h"

/**
 *swap - The function swaps two integers in array
 *@a: pointer to integer to swap
 *@b: pointer to integer to swap
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *selection_sort - sorts the array list using selection
 *@array: pointer to the array list
 *@size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size < 2)
		return;
	for (i = 0 ; i < size - 1 ; i++)
	{
		min_index = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
