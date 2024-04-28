
#include	<stdio.h>
#include	<stdlib.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	printList(Node	*head);
Node	*insertAtHead(Node	*head, int newValue);		// INSERT at the HEAD of a Linked List
Node	*insertAtTail(Node 	*head, int newValue);		// INSERT at the TAIL of a Linked List

int	main()
{
	Node	*myListHead;

	myListHead = NULL;

	myListHead = insertAtHead(myListHead, 7);
	myListHead = insertAtHead(myListHead, 5);
	myListHead = insertAtHead(myListHead, 3);
	myListHead = insertAtTail(myListHead, 10);
	myListHead = insertAtTail(myListHead, 12);
	myListHead = insertAtTail(myListHead, 14);

	printList(myListHead);

	return (0);
}

Node	*insertAtHead(Node 	*head, int newValue)		// INSERT at the HEAD of a Linked List
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

Node	*insertAtTail(Node 	*head, int newValue)		// INSERT at the TAIL of a Linked List
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
	int		i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
