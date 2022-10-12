#include "sort.h"
/**
 * swap_ahead - swap a node in listint_t doubly-linked list
 *              list of int with node ahead of it.
 * @list: pointer to the head of a doubly-linked lust of integers
 * @tail: pointer to the tail of the doubly-linked list of integers 
 * @shaker: pointer to the current swapping node of the cocktail shaker
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
  listint_t *temp = (*shaker)->next;

  if ((*shaker)->prev != NULL)
    (*shaker)->prev->next = temp;
  else
    *list = temp;

  temp->prev = (*shaker)->prev;
  (*shaker)->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = *shaker;
  else
    *tail = *shaker;

  (*shaker)->prev = temp;
  temp->next = *shaker;
  *shaker = temp;
}

/**
 * swap_behind - Swap a node in listint_t doubly-linked list
 *               of int with node behind it.
 * @list: pointer to the head of a doubly-linked list of ints
 * @tail: pointer to the tail of the doubly-linked list
 * @shaker: pointer to the current swapping node of the cocktaile shaker
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
  listint_t *temp = (*shaker)->prev;

  if ((*shaker)->next != NULL)
    (*shaker)->next->prev = temp;
  else
    *tail = temp;

  temp->next = (*shaker)->next;
  (*shaker)->prev = temp->prev;

  if (temp->prev != NULL)
    temp->prev->next = *shaker;
  else
    *list = *shaker;

  (*shaker)->next = temp;
  temp->prev = *shaker;
  *shaker = temp;
}


/**
 * cocktail_sort_list - inserts right unsorted side into left sorted side
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || !(*list) || (*list)->next == NULL)
	  return;
	
	for (tail = *list; tail->next != NULL;)
	  tail = tail->next;

	while (shaken_not_stirred == false)
	  {
	    shaken_not_stirred = true;
	    for (shaker = *list; shaker != tail; shaker = shaker->next)
	      {
		if (shaker->n > shaker->next->n)
		  {
		    swap_ahead(list, &tail, &shaker);
		    print_list((const listint_t *)*list);
		    shaken_not_stirred = false;
		  }
	      }
	    for (shaker = shaker->prev; shaker != *list;
		 shaker = shaker->prev)
	      {
		if (shaker->n < shaker->prev->n)
		  {
		    swap_behind(list, &tail, &shaker);
		    print_list((const listint_t *)*list);
		    shaken_not_stirred = false;
		  }
	      }
	  }
}
