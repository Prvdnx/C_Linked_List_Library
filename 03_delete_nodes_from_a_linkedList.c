
#include	<stdio.h>
#include	<stdlib.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	printList(Node	*head);
Node	*insertAtHead(Node	*head, int newValue);
Node	*insertAtTail(Node 	*head, int newValue);
Node	*deleteAtHead(Node	*head);
Node	*deleteAtTail(Node 	*head);

int	main()
{
	Node	*list1_head;

	list1_head = NULL;

	list1_head = insertAtHead(list1_head, 7);
	list1_head = insertAtHead(list1_head, 5);
	list1_head = insertAtHead(list1_head, 3);
	list1_head = insertAtTail(list1_head, 10);
	list1_head = insertAtTail(list1_head, 12);
	list1_head = insertAtTail(list1_head, 14);

	printList(list1_head);

	return (0);
}

Node	*insertAtHead(Node 	*head, int newValue)
{
	Node	*newNode = calloc(1, sizeof(Node));
	newNode->value = newValue;

	if (head == NULL)
		return (newNode);
	else
	{
		newNode->next = head;
		return (newNode);
	}
			// OR //
	// if (head != NULL)
	// {
	// 	newNode->next = head;
	// 	return (newNode);
	// }
	// return (newNode);
}

Node	*insertAtTail(Node 	*head, int newValue)
{
	Node	*newNode = calloc(1, sizeof(Node));
	newNode->value = newValue;

	if (head == NULL)
		return (newNode);
	else
	{
		Node	*current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		return (head);
	}
}

void	printList(Node	*head)
{
	Node	*current;
	current = head;
	int	i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
