#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Include your stack structure and function prototypes here

int main()
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	// Add some elements to stack a
	for (int i = 0; i < 5; i++)
	{
		t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->value = i;
		new_node->next = a;
		a = new_node;
	}

	// Add some elements to stack b
	for (int i = 5; i < 10; i++)
	{
		t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->value = i;
		new_node->next = b;
		b = new_node;
	}

	// Print the elements of stack a
	printf("Stack a before: ");
	t_stack *tmp = a;
	while (tmp != NULL)
	{
		printf("%ld ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");

	// Print the elements of stack b
	printf("Stack b before: ");
	t_stack *tmp2 = b;
	while (tmp2 != NULL)
	{
		printf("%ld ", tmp2->value);
		tmp2 = tmp2->next;
	}
	printf("\n");

	// Push the top element of stack b to stack a
	ft_r_rotate(&b);
	ft_push(&a, &b);
	ft_r_rotate(&b);
	ft_push(&a, &b);
	ft_r_rotate(&b);
	ft_push(&a, &b);
	ft_r_rotate(&b);
	ft_push(&a, &b);
	ft_push(&a, &b);
	ft_r_rotate(&a);
	ft_rotate(&a);

	// Print the elements of stack a
	printf("Stack a after: ");
	tmp = a;
	while (tmp != NULL)
	{
		printf("%ld ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");

	// Print the elements of stack b
	printf("Stack b after: ");
	tmp = b;
	while (tmp != NULL)
	{
		printf("%ld ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");

	return 0;
}
