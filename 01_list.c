
#include	<stdio.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	print_list(Node	*head);

int	main()
{
	Node	a;
	Node	b;
	Node	c;

	a.value = 5;
	b.value = 6;
	c.value = 7;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	print_list( &a );

	return (0);
}

void	print_list(Node	*head)
{
	Node	*current;
	int		i;

	current = head;
	i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
