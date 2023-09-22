#include "sort.h"

/**
 *swap - swap two intergers in the array
 *@a: pointer to swap
 *@b: pointer integer to swap
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *bubble_sort - sort the array of intergers
 *@array: pointer to tyhe array list
 *@size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		swapped = 0;
		for (j = 0 ; j < size - i - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
