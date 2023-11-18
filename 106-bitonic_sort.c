#include "sort.h"

/**
  *swap - performs swap on two integers
  *
  *@array: List of integers
  *@index_a: First integer
  *@index_b: Second integer
  *
  *Return: nothing
  */

void swap(int *array, int index_a, int index_b)
{
	int temp;

	temp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = temp;
}

/**
  *bitonicmerge - performs a merge sort on the bitonic sequence (could be
  *recursive)
  *@array: List of integers to be sorted
  *@size: Size of the array
  *@start: Index where bitonic sequence merge will start from
  *@seq: size of sequence to be merged
  *@flow: The direction of the sequence (Ascending or descending) aka sorting
  *direction
  *
  */

void bitonicmerge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t half = seq / 2, i;

	/*checks that the size of the sequence is greater than 1 to be a bitonic seq*/
	if (seq > 1)
	{
		/*Loop iterates over the first half of the sequence*/
		for (i = start; i < start + half; i++)
		{
			/*
			 * Determines if current element in 1st half should be swapped with
			 *corresponding element in the 2nd half, based on sorting flow/
			 *direction
			 */
			if ((flow == 'A' && array[i] > array[i + half]) ||
				(flow == 'D' && array[i] < array[i + half]))
			{
				swap(array, i, i + half);
			}
		}

		/*recursively calls itself on the two halves of the sequence*/
		bitonicmerge(array, size, start, half, flow);
		bitonicmerge(array, size, start + half, half, flow);
	}
}

/**
  *bitonic_seq - creates sorted bitonic sequence (recursively)
  *
  *@array: List of integers to be sorted
  *@size: Size of the array
  *@start: Index where bitonic sequencing will start from
  *@seq: size of sequence to be transformed into bitonic sequence
  *@flow: The direction of the sequence (Ascending or descending)
  *
  */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t half = seq / 2; /*Sequence is split into 2 halves*/
	char *str;

	/*
	 * if statement sets str based on the sorting direction to represent
	 *whether sequence is being merged in ascending or descending order
	 */
	if (flow == 'A')
	{
		str = "UP";
	}
	else
	{
		str = "DOWN";
	}

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		/*
		 * sequence is recursively split into 2 halves & bitonicmerge is
		 *called to merge them in sepcified order
		 */
		bitonic_seq(array, size, start, half, 'A');
		bitonic_seq(array, size, start + half, half, 'D');
		bitonicmerge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
  *bitonic_sort - sorts a given array using the bitonic sequence(Entry point
  *for algorithm)
  *
  *@array: List of integers
  *@size: size of the array
  *
  * Description: is a divide and conquer method that
  * works efficiently for arrays whose size is a power of 2
  */

void bitonic_sort(int *array, size_t size)
{
	/*checks valid input conditions*/
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 'A');
}
