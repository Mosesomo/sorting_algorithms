#include "sort.h"

/**
 *swap - swaps two elements of the array
 *@a: pointer to element to swap
 *@b: pointer to the element to swap
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *lomuto_partition - sort the array elements by assigning
 *the last element of the array to pivote
 *@array: pointer to array to sort
 *@size: size of the array
 *@first: first index elemnt of thr array
 *@last: last index element of the array
 *Return: always 0 on success
 */

int lomuto_partition(int *array, size_t size, int first, int last)
{
	int i, j, pivot;

	if (array == NULL || size < 2)
		return (0);

	pivot = array[last];
	i = first - 1;

	for (j = first ; j <= last - 1 ; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[last]);
	print_array(array, size);

	return (i + 1);
}

/**
 *quick_sort_recurse - recurses the lomuto partition
 *@array: pointer to the array
 *@size: size of the array
 *@first: first index
 *@last: last index
 */

void quick_sort_recurse(int *array, size_t size, int first, int last)
{
	int loc;

	if (array == NULL || size < 2)
		return;

	if (first < last)
	{
		loc = lomuto_partition(array, size, first, last);
		quick_sort_recurse(array, size, first, loc - 1);
		quick_sort_recurse(array, size, loc + 1, last);
	}
}

/**
 *quick_sort - sort the elements of the array using quick sort
 *@array: pointert to the array to sort
 *@size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recurse(array, size, 0, size - 1);
}
