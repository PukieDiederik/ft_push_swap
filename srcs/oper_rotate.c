#include "operations.h"

void rotate(t_stack **a, t_stack **b)
{
    *a = (*a)->prev;
    *b = (*b)->prev;
    ft_putstr_fd("rr\n", 1);
}

void rrotate(t_stack **a, t_stack **b)
{
    *a = (*a)->next;
    *b = (*b)->next;

    ft_putstr_fd("rrr\n", 1);
}

//returns pointer to top of stack
t_stack *rotate_a(t_stack **a)
{
    *a = (*a)->prev;
    ft_putstr_fd("ra\n", 1);
    return (*a);
}

t_stack *rrotate_a(t_stack **a)
{
    *a = (*a)->next;
    ft_putstr_fd("rra\n", 1);
    return (*a);
}

t_stack *rotate_b(t_stack **b)
{
    *b = (*b)->prev;
    ft_putstr_fd("rb\n", 1);
    return (*b);
}

t_stack *rrotate_b(t_stack **b)
{
    *b = (*b)->next;
    ft_putstr_fd("rrb\n", 1);
    return (*b);
}