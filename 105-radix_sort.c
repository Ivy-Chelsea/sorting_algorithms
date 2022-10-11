#include "sort.h"

int get_max(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - Get max value in an array of integers.
 * @array: An array of ints
 * @size: size of the array
 *
 * Return: The max int in the array
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_count_sort - Sort the significant digits of an array of int
 *                    in ascending order using the counting sort algorithm
 * @array: An array of int
 * @size: Size of the array
 * @sig: Significant digit to sort on.
 * @buff: A buffer to store the sorted array
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of int in ascending
 *              order using radix sort
 * @array: An array of integers
 * @size: size of the array
 *
 * Description: Implements the LSD radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}
	free(buff);
}
