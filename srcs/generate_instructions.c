#include "push_swap.h"
#include "stack.h"
#include <stdio.h>

void qs_partition(t_stack **a, t_stack **b, int amount);

void generate(t_stack **a)
{
	t_stack *b = 0;

    qs_partition(a, &b, 5);
}

void qs_partition(t_stack **a, t_stack **b, int amount)
{
    int i = -1;
    int j = 0;
    int size = (int)get_size_stack(*a);
    while (++i < size)
    {
        printf("pb\n");
        *a = (*a)->prev;
        *b = add_stack(*b, remove_stack((*a)->next));
    }
    *a = 0;
    i = 0;
    while (++i < amount)
    {
        int p = size - ((size / amount) * i);
        int b_size = (int)get_size_stack(*b);
        j = -1;
        while(++j < b_size)
        {
            if ((*b)->value >= p)
            {
                *b = (*b)->prev;
                *a = add_stack(*a, remove_stack((*b)->next));
                printf("pa\n");
            }
            else
            {
                *b = (*b)->prev;
                printf("rb\n");
            }
        }
    }
    amount++;
}