
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	<time.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	printList(Node	*head);
Node	*insertAtHead(Node *head, int newValue);
Node	*insertAtTail(Node *head, int newValue);
Node	*deleteAtHead(Node *head);
Node	*deleteAtTail(Node *head);
int		length(Node *head);		// Find the LENGTH of a Linked List
int		recursiveLength(Node *node);	// Find the LENGTH of a Linked List recursively
bool	isMember(Node *node, int findValue);	// SEARCH for a MEMBER in a Linked List
int		countMatches(Node *node, int findValue);	// Find & COUNT Matches in a Linked List
void	replaceMatches(Node	*node, int findValue,
								int replaceValue);	// Find & REPLACE Matches in a Linked List;
Node	*deleteFirstMatch(Node *head, int deleteValue,
								bool *wasDeleted);	// DELETE the first node to have a MATCHING value with the passed value
Node	*deleteAllMatches(Node *head, int deleteValue,
								int *numDeleted);	// DELETE all nodes with a value MATCHING with the passed value
Node	*efficientDeleteAllMatches(Node	*head, int deleteValue,
								int *numDeleted);	// Efficiently DELETE all nodes with a value MATCHING with the passed value
Node	*appendList(Node *head1, Node *head2);	// APPENDING (a node or list) to a Linked List
Node	*reverseList(Node *head);	// REVERSING a Linked List
void	sortList(Node *head);	// SORTING a Linked List
void	deleteDuplicates(Node *head);	// REMOVING Duplicates from a Linked List
Node	*insertAfter(Node *head, int newValue, int afterValue);	// INSERTING a node/value in Linked List after a particular node's value
Node	*deleteList(Node *node);		// DELETING a Linked List

int	main()
{
	Node	*myList = NULL;

	myList = insertAtTail(myList, 1);
	myList = insertAtTail(myList, 5);
	myList = insertAtTail(myList, 3);
	myList = insertAtTail(myList, 9);
	myList = insertAtTail(myList, 8);
	myList = insertAtTail(myList, 4);
	myList = insertAtTail(myList, 7);

	printf("\nMy List Before INSERTING new node/value...\n");
	printList(myList);
	myList = insertAfter(myList, 122, 4);	// INSERTING a node/value in Linked List after a particular node's value
	printf("\nMy List After INSERTING new node/value...\n");
	printList(myList);

	myList = deleteList(myList);
	printf("\nMy List After DELETING...\n");
	printList(myList);	

	return (0);
}

Node	*insertAfter(Node *head, int newValue, int afterValue)	// INSERTING a node/value in Linked List after a particular node's value
{
	Node	*newNode = calloc(1, sizeof(Node));
	newNode->value = newValue;
	
	if (head == NULL)
		return (newNode); 
	else
	{
		Node *current = head;
		while (current->next != NULL)
		{
			if (current->value == afterValue)
			{
				newNode->next = current->next; 
				current->next = newNode;
				return (head);
			}
			else
				current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		return (head);
	}
}

Node	*deleteList(Node *node)		// DELETING a Linked List
{
	if (node != NULL)
	{
		deleteList(node->next);
		free (node);
	}

	return (NULL);
}

void	sortList(Node *head)	// SORTING a Linked List
{
	if (head == NULL)
		return;
	if (head->next == NULL)
		return;

	bool	swapped = false;
	do
	{
		swapped = false; 
		Node	*current = head; 
		Node	*previous = NULL; 

		while (current->next != NULL)
		{
			previous = current;
			current = current->next; 
			if (current != NULL)
			{
				if ((current->value) < (previous->value))
				{
					int	temp;
					temp = previous->value;
					previous->value = current->value; 
					current->value = temp;
					swapped = true;
				}
			}      
		}
		
	} while (swapped);
}

void	deleteDuplicates(Node *head)	// REMOVING Duplicates from a Linked List
{
	if (head == NULL)
		return;
	if (head->next == NULL)
		return;

	Node	*current1;
	Node	*current2;
	Node	*duplicate;
	current1 = head; 

	while (current1 != NULL && current1->next != NULL)
	{
		current2 = current1;

		while (current2->next != NULL)
		{
			if (current1->value == current2->next->value)
			{
				duplicate = current2->next; 
				current2->next = current2->next->next;
				free (duplicate);
			}
			else
				current2 = current2->next;
		}

		current1 = current1->next;
	}
}

Node	*reverseList(Node *head)	// REVERSING a Linked List
{
	if (head == NULL)
		return (NULL); 
	if (head->next == NULL)
		return (head);

	Node	*current = head;
	Node	*nextNode = head->next; 

	current->next = NULL;

	while (nextNode != NULL)
	{
		Node	*temp = nextNode->next; 
		nextNode->next = current; 
		current = nextNode;
		nextNode = temp;
	}

	return (current);
}

Node	*appendList(Node *head1, Node *head2)	// APPENDING (a node or list) to a Linked List
{
	if (head1 == NULL)
		return (head2);

	Node *current = head1;
	while (current->next != NULL)
		current = current->next;
	current->next = head2;

	return (head1);
}

Node	*efficientDeleteAllMatches(Node	*head, int deleteValue, int *numDeleted)	// Efficiently DELETE all nodes with a value MATCHING with the passed value
{
	*numDeleted = 0;
	if (head == NULL)
		return (NULL);

	Node	*current = head;
	Node	*temp;
	Node	*newHead;

	while (current->value == deleteValue)
	{
		temp = current;
		current = current->next;
		free(temp);
		*numDeleted = *numDeleted + 1;

		if (current == NULL)
			return (NULL);
	}

	newHead = current;

	while (current->next != NULL)
	{
		if (current->next->value == deleteValue)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*numDeleted = *numDeleted + 1;
		}
		else
			current = current->next;
	}

	return (newHead);
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
