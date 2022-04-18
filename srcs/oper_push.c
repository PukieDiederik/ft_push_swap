#include "stack.h"
#include "libft.h"
#include <stdio.h>
#include "operations.h"

//returns pointer to pushed t_stack
t_stack *push_a(t_stack **a, t_stack **b)
{
    *b = (*b)->prev;
    *a = stack_add(*a, stack_remove((*b)->next));
    if (*a == *b)
        *b = 0;
    ft_putstr_fd("pa\n", 1);
    return (*a);
}

t_stack *push_b(t_stack **a, t_stack **b)
{
    *a = (*a)->prev;
    *b = stack_add(*b, stack_remove((*a)->next));
    if (*b == *a)
        *a = 0;
    ft_putstr_fd("pb\n", 1);
    return (*b);
}

