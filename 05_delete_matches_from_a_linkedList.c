
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>

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
int		length(Node	*head);		// Find the LENGTH of a Linked List
int		recursiveLength(Node	*node);		// Find the LENGTH of a Linked List recursively
bool	isMember(Node	*node, int findValue);	// SEARCH for a MEMBER in a Linked List
int		countMatches(Node	*node, int findValue);	// Find & COUNT Matches in a Linked List
void	replaceMatches(Node	*node, int findValue,
								int replaceValue);	// Find & REPLACE Matches in a Linked List;
Node	*deleteFirstMatch(Node	*head, int deleteValue,
								bool *wasDeleted);	// DELETE the first node to have a MATCHING value with the passed value
Node	*deleteAllMatches(Node	*head, int deleteValue,
								int *numDeleted);	// DELETE all nodes with a value MATCHING with the passed value


int	main()
{
	Node	*myListHead;

	myListHead = NULL;

	myListHead = insertAtHead(myListHead, 7);
	myListHead = insertAtHead(myListHead, 5);
	myListHead = insertAtHead(myListHead, 3);
	myListHead = insertAtTail(myListHead, 5);
	myListHead = insertAtTail(myListHead, 10);
	myListHead = insertAtTail(myListHead, 10);
	myListHead = insertAtTail(myListHead, 10);
	myListHead = insertAtTail(myListHead, 12);
	myListHead = insertAtTail(myListHead, 14);

	printf("\nList before DELETING Matches...\n");
	printList(myListHead);
	
	// bool	deleted;
	// myListHead = deleteFirstMatch(myListHead, 3, &deleted);	// DELETE the first node to have a MATCHING value
	// if (deleted)
	// {
	// 	printf("\nA node with value 3 was deleted!\n");
	// 	printf("List after DELETING...\n");
	// 	printList(myListHead);
	// }
	// else
	// 	printf("\nA node with value 3 was not deleted!\n");

	// myListHead = deleteFirstMatch(myListHead, 8, &deleted);	// DELETE the first node to have a MATCHING value
	// if (deleted)
	// {
	// 	printf("\nA node with value 8 was deleted!\n");
	// 	printf("List after DELETING...\n");
	// 	printList(myListHead);
	// }
	// else
	// 	printf("\nA node with value 8 was not deleted!\n");

	// myListHead = deleteFirstMatch(myListHead, 10, &deleted);	// DELETE the first node to have a MATCHING value
	// if (deleted)
	// {
	// 	printf("\nA node with value 10 was deleted!\n");
	// 	printf("List after DELETING...\n");
	// 	printList(myListHead);
	// }
	// else
	// 	printf("\nA node with value 10 was not deleted!\n\n");

	int	numDeleted;
	myListHead = deleteAllMatches(myListHead, 5, &numDeleted);	// DELETE all nodes with a value MATCHING with the passed value
	printf("\n%d nodes with value 5 was deleted!\n", numDeleted);
	printf("List after DELETING...\n");
	printList(myListHead);	

	myListHead = deleteAllMatches(myListHead, 10, &numDeleted);	// DELETE all nodes with a value MATCHING with the passed value
	printf("\n%d nodes with value 10 was deleted!\n", numDeleted);
	printf("List after DELETING...\n");
	printList(myListHead);	

	return (0);
}

Node	*deleteFirstMatch(Node	*head, int deleteValue, bool *wasDeleted)	// DELETE the first node to have a MATCHING value with the passed value
{
	if (head == NULL)
	{
		*wasDeleted = false;
		return (NULL);
	}

	if (head->value == deleteValue)
	{
		Node	*temp = head->next;
		free (head);
		*wasDeleted = true;
		return (temp);
	}

	Node	*current = head->next;
	Node	*previous = head;

	while (current != NULL)
	{
		if (current->value == deleteValue)
		{
			previous->next = current->next;
			free (current);
			*wasDeleted = true;
			return (head);
		}
		
		previous = current;
		current = current->next;
	}

	*wasDeleted = false;
	return (head);
}

Node	*deleteAllMatches(Node	*head, int deleteValue, int *numDeleted)	// DELETE all nodes with a value MATCHING with the passed value
{
	Node	*current = head;
	bool	deleted = false;
	*numDeleted = 0;

	do
	{
		current = deleteFirstMatch(current, deleteValue, &deleted);
		if (deleted)
			*numDeleted = *numDeleted + 1;
	} while (deleted);
	
	return (current);
}

int	length(Node	*head)		// Find the LENGTH of a Linked List
{
	Node	*current;
	current = head;
	int		length = 0;

	while (current != NULL)
	{
		length++;
		current = current->next;
	}

	return (length);
}

int	recursiveLength(Node	*node)		// Find the LENGTH of a Linked List recursively
{
	if (node == NULL)
		return (0);
	else
		return (1 + recursiveLength(node->next));
}

bool	isMember(Node	*node, int findValue)	// SEARCH for a MEMBER in a Linked List
{
	if (node == NULL)
		return (false);
	else if (node->value == findValue)
		return (true);
	else
		return (isMember(node->next, findValue));
}

int	countMatches(Node	*node, int findValue)	// Find and COUNT Matches in a Linked List
{
	if (node == NULL)
		return (0);
	else if (node->value == findValue)
		return (1 + isMember(node->next, findValue));
	else
		return (countMatches(node->next, findValue));
}

void	replaceMatches(Node	*node, int findValue, int replaceValue)	// Find & REPLACE Matches in a Linked List;
{
	if (node != NULL)
	{
		if (node->value == findValue)
			node->value = replaceValue;

		replaceMatches(node->next, findValue, replaceValue);
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

Node	*deleteAtHead(Node	*head)
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

Node	*deleteAtTail(Node	*head)
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
	int		i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
