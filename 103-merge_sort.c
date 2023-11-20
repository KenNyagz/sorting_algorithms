#include "sort.h"

/**
*print_mini_array - print visualizes sublists and merging
*@array: array sublist
*@size: sublist size
*@index: starting index of subarray
*/

void print_mini_array(int *array, size_t size, size_t index)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[index + i]);
		if (i < size - 1)
		printf(", ");
	}
}

/**
*merge - joins two arrays
*@array: array to be sorted
*@left_size: size of first subarray
*@right_size: size of second subarray
*Return: void
*/

void merge(int *array, size_t left_size, size_t right_size)
{
	size_t total_size = left_size + right_size, i = 0;
	size_t left_index = 0, right_index = left_size, temp_index = 0;
	int *temp_array = malloc(total_size * sizeof(int));

	if (temp_array == NULL)
		return;

	printf("Merging...\n[left]: ");
	print_mini_array(array, left_size, left_index);

	printf("\n[right]: ");
	print_mini_array(array, right_size, right_index);
	printf("\n");
	/*Merge the two sorted halves*/
	while (left_index < left_size && right_index < total_size)
	{
		if (array[left_index] <= array[right_index])
			temp_array[temp_index++] = array[left_index++];
		else
			temp_array[temp_index++] = array[right_index++];
	} /*Copy remaining elements from the left half, if any*/
	while (left_index < left_size)
		temp_array[temp_index++] = array[left_index++];
	/*Copy remaining elements from the right half, if any*/
	while (right_index < total_size)
		temp_array[temp_index++] = array[right_index++];
	/*Copy merged elements back to the original array*/
	for (i = 0; i < total_size; i++)
		array[i] = temp_array[i];
	printf("[Done]: ");
	for (i = 0; i < total_size; i++)
	{
		printf("%d", array[i]);
		if (i < total_size - 1)
			printf(", ");
	}
	printf("\n");

	free(temp_array);
}

/**
*merge_sort_helper - responsible for merge_sorts recursive calls
*@array: - array to be sorted
*@size: size of array
*Return: Nothing
*/

void merge_sort_helper(int *array, size_t size)
{
	size_t mid = 0;

	if (size > 1)
	{
		mid = size / 2;

		/*Recursive calls to sort the left and right halves*/
		merge_sort_helper(array, mid);
		merge_sort_helper(array + mid, size - mid);

		/*Merge sorted halves*/
		merge(array, mid, size - mid);

	}
}

/**
*merge_sort - sorts an array of integers in ascending
*             order using the Merge sort algorithm
*@array: array to be sorted
*@size: sixe of the array
*
*/

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_helper(array, size);
}
