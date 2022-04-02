#include "stack.h"

t_stack	*create_stack(int value) //creates a new stack element
{
	t_stack *s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->next = s;
	s->prev = s;
	s->value = value;

	return (s);
}
t_stack	*remove_stack(t_stack *s) //removes (and returns) a stack from the list
{
	s->prev->next = s->next;
	s->next->prev = s->prev;
	s->prev = s;
	s->next = s;
	return (s);
}
void	delete_stack(t_stack *s) //deletes/frees the stack element
{
	free(s);
}
void	clear_stack(t_stack *s) //deletes the entire list of stacks
{
	t_stack *temp;
    if (s) {
        s->prev->next = 0;
        while (s) {
            temp = s->next;
            free(s);
            s = temp;
        }
    }
}

t_stack	*add_stack(t_stack *orig, t_stack *s) // adds 's' after orig
{
	if (!orig)
		return (s);
	s->next = orig->next;
	s->prev = orig;
	s->next->prev = s;
	orig->next = s;
	return (s);
}