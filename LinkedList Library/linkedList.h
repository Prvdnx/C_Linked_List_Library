
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	<time.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	printList(Node	*head); // PRINTING Linked List
Node	*insertAtHead(Node	*head, int newValue);   // INSERT at the HEAD of a Linked List
Node	*insertAtTail(Node 	*head, int newValue);	// INSERT at the TAIL of a Linked List
Node	*deleteAtHead(Node	*head); // DELETE at the HEAD of a Linked List
Node	*deleteAtTail(Node 	*head); // DELETE at the TAIL of a Linked List
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
Node	*deleteList(Node *node);	// DELETING a Linked List
void	addLists(Node *list1, Node *list2);	// ADD the values of one List to the values of another List
Node	*duplicateList(Node *node);	// Create a DUPLICATE for a given List on the heap
Node	*mergeSortedLists(Node *list1, Node *list2);	// MERGE 2 Sorted Lists and return it as one Sorted List
