#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @array: contains a list of integers
 * @index_a: The first integer to swap.
 * @index_b: The second integer to swap.
 */

void swap(int *array, int index_a, int index_b)
{
	int temp;

	temp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = temp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to sort.
 * @high: The ending index of the subset to sort.
 *
 * Return: Pivot position.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];

    for (i = low - 1, j = high + 1; ; )
    {
		do {
			i++;
		} while (array[i] < pivot);
		do {
		    j--;
		} while (array[j] > pivot);

		if (i >= j)
            return (j);

        swap(array, i, j);
        print_array(array, size);
	}
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to sort.
 * @high: The ending index of the array partition to sort.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int p_index;

	if (high - low > 0)
	{
		p_index = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, p_index - 1);
		hoare_sort(array, size, p_index + 1, high);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

    hoare_sort(array, size, 0, size - 1);
}
