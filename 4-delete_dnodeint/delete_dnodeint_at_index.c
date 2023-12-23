#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *saved_head;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	saved_head = *head;
	current = *head;

	/* Handle case where the first node needs to be deleted */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse the list to the node to be deleted */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	/* Check if the index is out of bounds */
	if (current == NULL)
	{
		*head = saved_head;
		return (-1);
	}

	/* Adjust pointers to remove the node */
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	*head = saved_head;

	return (1);
}
