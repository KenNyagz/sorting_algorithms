#include "sort.h"

/**
*merge - joins two arrays
*@array: array to be sorted
*@temp: temporary mini array sliced from prior array
*@left_start: start of first slice/half array
*@left_end: end of first half of original array
*@right_start: first of second half of half array
*@right_end: end of second half array
*Return: void
*/

void merge(int *array, int *temp, size_t left_start, size_t left_end,
	 size_t right_start, size_t right_end)
{
	size_t i = 0, j = 0, k = 0, p = 0;

	i = left_start;
	j = right_start;
	k = left_start;

	while (i <= left_end && j <= right_end)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= left_end)
		temp[k++] = array[i++];

	while (j <= right_end)
		temp[k++] = array[j++];

	for (p = left_start; p <= right_end; p++)
	{
		array[p] = temp[p];
	}
}

/**
*merge_sort_helper - responsible for merge_sorts recursive calls as
*		well as printf visualisations
*@array: - array to be sorted
*@temp: temporary mini array which is half of the original array
*@start: left end of array
*@end: right end of array
*Return: Nothing
*/

void merge_sort_helper(int *array, int *temp, size_t start, size_t end)
{
	size_t mid = 0, i = 0;

	if (start >= end)
		return;

	mid = start + (end - start) / 2;

	merge_sort_helper(array, temp, start, mid);
	merge_sort_helper(array, temp, mid + 1, end);

	printf("Merging...\n");
	printf("[Left]: ");
	for (i = start; i <= mid; i++)
		printf("%d ", array[i]);
	printf("\n");

	printf("[right]: ");
	for (i = mid + 1; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");

	merge(array, temp, start, mid, mid + 1, end);

	printf("[Done]: ");
	for (i  = start; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");
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
	int *temp = NULL;

	temp = (int *)malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_helper(array, temp, 0, size - 1);
	free(temp);
}
