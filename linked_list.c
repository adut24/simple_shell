#include "main.h"

/**
 * add_node - create a node
 * @head: linked list in which to add the node
 * @s: string to put in the node
 * Return: pointer to the new node
 */
tok_t *add_node(tok_t **head, char *s)
{
	tok_t *t = NULL, *new = NULL;

	new = malloc(sizeof(tok_t));
	if (new == NULL)
		return (NULL);
	new->str = s;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		t = *head;
		while (t->next)
			t = t->next;
		t->next = new;
	}
	return (new);
}

/**
 * free_list - free a list
 * @head: list to free
 */
void free_list(tok_t **head)
{
	if (head)
	{
		tok_t *t;

		t = *head;
		while (*head)
		{
			t = (*head)->next;
			free(*head);
			*head = t;
		}
		*head = NULL;
	}
}
