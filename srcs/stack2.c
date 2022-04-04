#include "stack.h"

unsigned int	get_size_stack(const t_stack *s)
{
	t_stack *current;
	int size;

	if (!s)
		return (0);
	current = s->next;
	size = 1;
	while (current != s)
	{
		current = current->next;
		size++;
	}
	return (size);
}