#include "sort.h"

/**
  *
  *
  *
  *
  *
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
  *
  *
  *
  *
  *
  *
  *
  */

void counting_sort(int *array, size_t size)
{
    size_t i, k;
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

    /*Initialize all elements with zero*/
    for (i = 0; i < (k + 1); i++)
        count[i] = 0;

    /*Get the count of times that integers appear in array*/
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /*Perform a cumulative addition on the integers from left to right*/
    for (i = 1; i <= k; i++)
        count[i] = count[i] + count[i - 1];
    /*Build Output array*/
    for (i = size - 1; i <= size; i--)
        output_array[--count[array[i]]] = array[i];

    print_array(count, (k + 1));

    /*Copy sorted list from Output array to initial array*/

    for (i = 0; i < size; i++)
        array[i] = output_array[i];


    free(output_array);
    free(count);

}
