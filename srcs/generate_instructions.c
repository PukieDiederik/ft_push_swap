#include "push_swap.h"
#include "stack.h"
#include <stdio.h>

int qs_partition(t_stack *a, t_stack *b, int start, int end);

void generate(t_stack *a)
{
	unsigned int size = get_size_stack(a);
	t_stack *b = 0;

	qs_partition(a, b, 0, size);
}

int qs_partition(t_stack *a, t_stack *b, int start, int end)
{
	int i = -1;
	int p = (end - 1 - start) / 2;
	while (++i < end - start)
	{
		if (a->value <= p)
		{
			a = a->prev;
			b = add_stack(b, remove_stack(a->next));
			printf("pb\n");
		}
		else
		{
			a = a->prev;
			printf("ra\n");
		}
	}
	return (0);
}