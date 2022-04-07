#include "stack.h"
#include "push_swap.h"

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
		s = s->prev; //because of the way the lists get created
	}
	return (arr);
}

void stack_index(t_stack *s)
{
    int size;
    int i;
    int j;
    int *sorted;

    size = (int) get_size_stack(s);
    sorted = stack_to_array(s);
    quicksort(sorted, 0, size);
    i = 0;
    while (i++ < size)
    {
        j = 0;
        while (j < size && s->value != sorted[j])
            j++;
        s->value = j;
        s = s->next;
    }
    free(sorted);
}