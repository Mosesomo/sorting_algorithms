#include "sort.h"

/**
 *swap - swaps two integers in the array
 *@a: pointer to the integer to swap
 *@b: pointer to the integer to swap
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *shell_sort - sorts the array of integers using
 *shell sort algorithm
 *@array: pointer to the array to sort
 *@size: size of the array to sort
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap >= 1)
	{
		for (i = gap ; i < size ; i++)
		{
			for (j = i ; j >= gap ; j -= gap)
			{
				if (array[j] < array[j - gap])
				{
					swap(&array[j], &array[j - gap]);
					print_array(array, size);
				}
				else
					break;
			}
		}
		gap = (gap - 1) / 3;
	}
}
