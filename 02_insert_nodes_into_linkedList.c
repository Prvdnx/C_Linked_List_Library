
#include	<stdio.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	printList(Node	*head);
Node    *insertAtHead(Node  *head, int newValue);

int	main()
{
	Node	*list1_head;

    list1_head = NULL;

	printList(list1_head);

	return (0);
}

Node    *insertAtHead(Node  *head, int newValue)
{
    Node    *newNode = calloc(1, sizeof(Node));
    newNode->value = newValue;

    if (head == NULL)
        return (newNode);

}

void	printList(Node	*head)
{
	Node	*current;
	current = head;
	int i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
