#include "get_next_line.h"
#include <stdio.h>

void add_last(node_t **head)
{
	node_t *current;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (node_t*)malloc(sizeof(node_t));
	current->next->val = 2;
	current->next->next = NULL;
}

void add_new_head(node_t **head)
{
	node_t *new_head;
	new_head = (node_t*)malloc(sizeof(node_t));
	new_head->val = -1;
	new_head->next = *head;
	*head = new_head;
}

void remove_from_head(node_t **head)
{
	node_t *remove;

	remove = (*head)->next;
	free(*head);
	*head = remove;
}

int remove_index(node_t **head, int n)
{
	int i;

	i = 0;
	node_t *remove;
	node_t *pls;
	remove = *head;
	while (i < n - 1)
	{
		if (remove->next->next == NULL)
		{
			return (0);
		}
		remove = remove->next;
		i++;
	}
	pls = remove->next->next;
	free(remove->next);
	remove = pls;
	return (1);
}

void remove_last(node_t **head)
{
	node_t *remove;

	remove = *head;
	while (remove->next->next != NULL)
		remove = remove->next;
	free(remove->next);
	remove->next = NULL;
}

int main()
{
	node_t *head = NULL;
	node_t *current;
	head = (node_t*)malloc(sizeof(node_t));
	head->val = 0;
	head->next = (node_t*)malloc(sizeof(node_t));
	head->next->val = 1;
	head->next->next = NULL;
	add_new_head(&head);
	remove_index(&head,2);
	current = head;
	add_last(&head);
	while (current != NULL)
	{
		printf("%d\n",current->val);
		current = current->next;
	}
}
