#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i, j, min;

	/*Check if array is empty or has 1 element*/
	if (array == NULL || size < 2)
		return;
	/*Outer loop iterates throught the indexes of the array minus 1*/
	for (i = 0; i < size - 1; i++)
	{
		min = i; /*Set the current index as the minimum*/
		for (j = i + 1; j < size; j++)
		{
		if (array[j] < array[min])
			min = j; /*Updates minimum*/
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
