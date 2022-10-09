#include "sort.h"

/**
 * print_list - prints a list of integers
 * @list: list to be printed
 */
void print_list(const listint_t *list)
{
	int g;

	g = 0;
	while (list)
	{
		if (g > 0)
			printf(", ");
		printf("%d", list->n);
		++g;
		list = list->next;
	}
	printf("\n");
}
