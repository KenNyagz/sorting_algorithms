#include "sort.h"

/**
  *find_max - finds max int from array
  *@array: array with data to be sorted
  *@size: length of array
  *Return: maximum int found
  */

int find_max(int *array, int size)
{
	int max, k;

	for (max = array[0], k = 1; k < size; k++)
	{
		if (array[k] > max)
		max = array[k];
	}
	return (max);
}

/**
  *radix_sort - sorts an array of integers
  *@array: the array
  *@size: length of array
  *
  */

void radix_sort(int *array, size_t size)
{
	size_t i, k, pos, max_digit = 10;
	int *count, *output_array;

	if (array == NULL || size < 2)
		return;

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
		return;
	k = find_max(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(output_array);
		return;
	}
	for (pos = 1; (k / pos) > 0; pos *= 10)
	{
		/*Initialize all elements with zero*/
		for (i = 0; i < max_digit; i++)
			count[i] = 0;
		/*Get the count of times that integers appear in array - frequency*/
		for (i = 0; i < size; i++)
			++count[(array[i] / pos) % 10];
		/*Perform a cumulative addition on the integers from left to right*/
		for (i = 1; i < max_digit; i++)
			count[i] = count[i] + count[i - 1];

		/*Build Output array*/
		for (i = size - 1; i <= size; i--)
			output_array[--count[(array[i] / pos) % 10]] = array[i];

		print_array(output_array, size);

		/*Copy sorted list from Output array to initial array*/
		for (i = 0; i < size; i++)
			array[i] = output_array[i];
	}
	free(output_array);
	free(count);
}
