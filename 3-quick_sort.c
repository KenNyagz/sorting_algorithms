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
  * quick_sort - implements quick sort on an array
  * @array: the array to sort
  * @size: the size of the array
  * Return: nothing, void
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, (size - 1));
}


/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to sort.
 * @end: The ending index of the array partition to sort.
 *
 * Return: Nothing
 */

void lomuto_sort(int *array, size_t size, int start, int end)
{
	int p_index;

	if (start < end)
	{
		p_index = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, p_index - 1);
		lomuto_sort(array, size, p_index + 1, end);
	}
}

/**
 * lomuto_partition - sorts from within an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset tosort.
 * @end: The ending index of the subset to sort.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end], p_index, i;

	for (p_index = i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
            if (p_index < i)
            {
                swap(array, i, p_index);
                print_array(array, size);
            }
            p_index++;
		}
	}
    if (array[p_index] > pivot)
    {
        swap(array, p_index, end);
        print_array(array, size);
    }

	return (p_index);
}
