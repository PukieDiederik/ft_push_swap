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

int *stack_to_array(const t_stack *s)
{
	int *arr;
	int size;
	int i;

	if (!s)
		return (0);
	size = get_size_stack(s);
	arr = malloc(size * sizeof(int));
	i = -1;
	while(++i < size)
	{
		arr[i] = s->value;
		s = s->next;
	}
	return (arr);
}