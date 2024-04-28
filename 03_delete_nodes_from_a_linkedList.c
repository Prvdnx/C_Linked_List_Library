
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
	Node	*list1_head;

	list1_head = NULL;

	list1_head = insertAtHead(list1_head, 7);
	list1_head = insertAtHead(list1_head, 5);
	list1_head = insertAtHead(list1_head, 3);
	list1_head = insertAtTail(list1_head, 10);
	list1_head = insertAtTail(list1_head, 12);
	list1_head = insertAtTail(list1_head, 14);

	printf("\nBefore delete at HEAD and TAIL...\n");
	printList(list1_head);

	list1_head = deleteAtHead(list1_head);
	list1_head = deleteAtHead(list1_head);
	printf("After delete at HEAD...\n");
	printList(list1_head);

	list1_head = deleteAtTail(list1_head);
	list1_head = deleteAtTail(list1_head);
	printf("After delete at TAIL...\n");
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
	printf("\n");
}
