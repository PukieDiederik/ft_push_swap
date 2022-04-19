#include "push_swap.h"
#include "stack.h"
#include "libft.h"
#include "limits.h"
#include "operations.h"

void qs_partition(t_stack **a, t_stack **b, int amount);
void sort(t_stack **a, t_stack **b);
void push_to_b(t_stack **a, t_stack **b, int amount, int i);
t_stack *sort_find_smallest(t_stack **a, t_stack **b);

void generate(t_stack **a)
{
	t_stack *b = 0;
//	int i = 0;
	int amount = 5;
    if (stack_get_size(*a) > 100)
        amount = 10;

    qs_partition(a, &b, amount);
	sort(a, &b);
//	while(++i < amount) {
//		push_to_b(a, &b, amount, i);
//		sort(a, &b);
//	}
	while ((*a)->value != 0)
        rotate_a(a);
}

void qs_partition(t_stack **a, t_stack **b, int amount)
{
    int i = 0;
    int j = 0;
    int size = (int) stack_get_size(*a);
    int v_size;
    while (i++ < amount)
	{
    	v_size = stack_get_size(*a);
		int p = size - ((size / amount) * i);
		j = 0;
		while(++j < v_size)
        {
            if ((*a)->value >= p && (*a)->value != 0)
                push_b(a, b);
            else
                rotate_a(a);
        }
	}
//    while (++i < size)
//    {
//    	if ((*a)->value == 0)
//            rotate_a(a);
//		else
//            push_b(a, b);
//    }
//    i = 0;
//    while (++i < amount)
//    {
//        int p = size - ((size / amount) * i);
//        int b_size = (int) stack_get_size(*b);
//        j = -1;
//        while(++j < b_size)
//        {
//            if ((*b)->value >= p)
//                push_a(a, b);
//            else
//                rotate_b(b);
//        }
//    }
}

void sort(t_stack **a, t_stack **b)
{
    while(*b)
	{
        sort_find_smallest(a, b);
	}
}

void push_to_b(t_stack **a, t_stack **b, int amount, int i)
{
	int size = (int) stack_get_size(*a);
	int j;
	int p = (size - (size / amount) * (amount - i));

//	*b = 0;
	while ((*a)->value < p)
        rotate_a(a);
	j = 0;
	while (j++ < (size / amount))
        push_b(a, b);
}

//min inclusive, max exclusive
t_stack *sort_find_smallest(t_stack **a, t_stack **b)
{
    t_stack *smallest_stack;
    unsigned int smallest_opps;
    unsigned int smallest_dir;
    unsigned int i;
    unsigned int cost;
    unsigned int size;
    t_stack *tmp;
    t_stack *tmp2;

    tmp = *a;
    size = stack_get_size(*b);
    i = -1;
    tmp2 = (*b)->next;
    smallest_stack = 0;
    smallest_opps = INT_MAX;
    while (++i < size)
    {
        cost = 0;
        tmp = *a;
        tmp2 = tmp2->prev;
        while (!((tmp->value > tmp2->value && tmp->next->value < tmp2->value)
               || (tmp->value == 0 && tmp->next->value < tmp2->value)))
        {
            if (tmp->value > tmp2->value)
                tmp = tmp->next;
            else
                tmp = tmp->prev;
            cost++;
        }
        if (i > size / 2)
        	cost += (size / 2) - (i - (size / 2));
        else
        	cost += i;
        if (cost < smallest_opps)
        {
            smallest_stack = tmp2;
            smallest_opps = cost;
            smallest_dir = i / (size / 2 + 1);
        }
    }
    if (!smallest_stack)
        return (0);
    //rotate to it and push
    if (smallest_dir)
        while (*b != smallest_stack)
            rrotate_b(b);
    else
        while (*b != smallest_stack)
            rotate_b(b);
    while (!(((*a)->value > (*b)->value && (*a)->next->value < (*b)->value)
        || ((*a)->value == 0 && (*a)->next->value < (*b)->value)))
    {
        if ((*a)->value > (*b)->value)
            rrotate_a(a);
        else
            rotate_a(a);
    }

    push_a(a, b);
    return (smallest_stack);
}