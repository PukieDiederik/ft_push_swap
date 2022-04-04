#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack	*create_stack(int value); //creates a new stack element
t_stack	*remove_stack(t_stack *s); //removes (and returns) a stack from the list
void	delete_stack(t_stack *s); //deletes/frees the stack element
void	clear_stack(t_stack *s); //deletes the entire list of stacks
t_stack	*add_stack(t_stack *orig, t_stack *s); // adds 's' after orig
unsigned int		get_size_stack(const t_stack *s); // gets the amount of elements in stacks s

#endif