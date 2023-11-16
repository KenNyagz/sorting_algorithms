#include "sort.h"

/**
*bubble_sort - implements the bubble sort algorythm
*@array: array to be sorted
*@size: size of the array
*
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	short int flag = 0;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
