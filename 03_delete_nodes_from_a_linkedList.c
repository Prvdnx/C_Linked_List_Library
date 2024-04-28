
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
Node	*deleteAtHead(Node	*head);		// DELETE at the HEAD of a Linked List
Node	*deleteAtTail(Node 	*head);		// DELETE at the TAIL of a Linked List

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

	printf("\nBefore DELETE at HEAD and TAIL...\n");
	printList(myListHead);

	myListHead = deleteAtHead(myListHead);
	myListHead = deleteAtHead(myListHead);
	printf("After DELETE at HEAD...\n");
	printList(myListHead);

	myListHead = deleteAtTail(myListHead);
	myListHead = deleteAtTail(myListHead);
	printf("After DELETE at TAIL...\n");
	printList(myListHead);

	return (0);
}

Node	*deleteAtHead(Node	*head)		// DELETE at the HEAD of a Linked List
{
	if (head == NULL)
		return (NULL);
	else
	{
		Node	*toReturn = head->next;
		free (head);
		return (toReturn);
	}
}

Node	*deleteAtTail(Node	*head)		// DELETE at the TAIL of a Linked List
{
	if (head == NULL)
		return (NULL);
	else if (head->next == NULL)
	{
		free (head);
		return (NULL);
	}
	else
	{
		Node	*current = head;
		Node	*previous = NULL;

		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}

		previous->next = NULL;
		free (current);
		return (head);
	}
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
	int		i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
	printf("\n");
}
