#include "push_swap.h"
#include "stack.h"
#include <stdio.h>

void qs_partition(t_stack **a, t_stack **b, int amount);
void sort(t_stack **a, t_stack **b);
void push_b(t_stack **a, t_stack **b, int amount, int i);

void generate(t_stack **a)
{
	t_stack *b = 0;
	int i = 1;
	int amount = 5;

    qs_partition(a, &b, amount);
	sort(a, &b);
	push_b(a, &b, amount, i++);
	sort(a, &b);
	push_b(a, &b, amount, i++);
	sort(a, &b);
	push_b(a, &b, amount, i++);
	sort(a, &b);
	push_b(a, &b, amount, i++);
	sort(a, &b);
	while ((*a)->value != 0)
	{
		*a = (*a)->prev;
		printf("ra\n");
	}
}

void qs_partition(t_stack **a, t_stack **b, int amount)
{
    int i = -1;
    int j = 0;
    int size = (int)get_size_stack(*a);
    while (++i < size)
    {
    	if ((*a)->value == 0)
		{
    		printf("ra\n");
    		*a = (*a)->prev;
			continue;
		}
        printf("pb\n");
        *a = (*a)->prev;
        *b = add_stack(*b, remove_stack((*a)->next));
    }
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

void sort(t_stack **a, t_stack **b)
{
	while(*b)
	{
		if (((*a)->value > (*b)->value && (*a)->next->value < (*b)->value)
			|| ((*a)->value == 0 && (*a)->next->value < (*b)->value))
		{
			*b = (*b)->prev;
			*a = add_stack(*a, remove_stack((*b)->next));
			if (*b == *a)
				*b = 0;
			printf("pa\n");
		}
		else
		{
			if ((*a)->value > (*b)->value)
			{
				*a = (*a)->next;
				printf("rra\n");
			}
			else
			{
				*a = (*a)->prev;
				printf("ra\n");
			}
		}
	}
}

void push_b(t_stack **a, t_stack **b, int amount, int i)
{
	int size = (int)get_size_stack(*a);
	int j;
	int p = (size - (size / amount) * (amount - i));

//	*b = 0;
	while ((*a)->value < p)
	{
		*a = (*a)->prev;
		printf("ra\n");
	}
	j = 0;
	while (j++ < (size / amount))
	{
		*a = (*a)->prev;
		*b = add_stack(*b, remove_stack((*a)->next));
		printf("pb\n");
	}
}