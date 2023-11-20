#include "sort.h"

/**
*merge - joins two arrays
*@array: array to be sorted
*@left: start array(and subsequent sb arrays)
*@mid: midpoint of array(and subsequent sub arrays)
*@right: end of  array(and subsequent sub arrays)
*Return: void
*/

void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i = 0, j = 0, k = 0; 
	size_t n1 = mid - left + 1, n2 = right - mid;
	int *leftArray , *rightArray;

	leftArray = malloc(sizeof(int) * n1);
	rightArray = malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
		leftArray[i] = array[left + i];
	for (j = 0; j < n2; j++)
		rightArray[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		}
		else
		{
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = rightArray[j];
		j++;
		k++;
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

void merge_sort_helper(int *array, size_t left, size_t right)
{
	size_t mid = 0;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_helper(array, left, mid);
		merge_sort_helper(array, mid + 1, right);
/*
	printf("Merging...\n");
	printf("[Left]: ");
	for (i = start; i <= mid; i++)
		printf("%d ", array[i]);
	printf("\n");

	printf("[right]: ");
	for (i = mid + 1; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");
*/
	merge(array, left, mid, right);

/*	printf("[Done]: ");
	for (i  = start; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");*/
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
	int *temp = NULL;

	if (!array || size < 2)
		return;
	temp = (int *)malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_helper(array, 0, size - 1);
	free(temp);
}
