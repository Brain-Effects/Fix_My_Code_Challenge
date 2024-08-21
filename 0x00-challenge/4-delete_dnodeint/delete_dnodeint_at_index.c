#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position.
 * @head: Pointer to the head of the doubly linked list.
 * @index: Index of the node to delete (starting from 0).
 * Return: 1 if successful, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *temp;
    unsigned int i = 0;

    if (!head || !*head)
        return (-1);

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    while (current && i < index)
    {
        current = current->next;
        i++;
    }

    if (!current)
        return (-1);

    temp = current->prev;
    temp->next = current->next;
    if (current->next)
        current->next->prev = temp;
    free(current);
    return (1);
}
