
#include	<stdio.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

int	main()
{
	Node	a;
	a.value = 5;

	printf("Node a.value: %d\n", a.value);

	return (0);
}
