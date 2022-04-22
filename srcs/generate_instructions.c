#include "push_swap.h"
#include "stack.h"
#include "limits.h"
#include "operations.h"

void qs_partition(t_stack **a, t_stack **b, unsigned int amount);
void sort(t_stack **a, t_stack **b);
t_stack *sort_find_smallest(t_stack **a, t_stack **b);

void generate(t_stack **a)
{
	t_stack *b = 0;
	unsigned int amount = 20;
    if (stack_get_size(*a) > 100)
		amount = 50;

    qs_partition(a, &b, amount);
	sort(a, &b);
	if ((*a)->value < (int)stack_get_size(*a) / 2)
		while ((*a)->value != 0)
        	rrotate_a(a);
	else
		while ((*a)->value != 0)
			rotate_a(a);
}

void qs_partition(t_stack **a, t_stack **b, unsigned int amount)
{
    unsigned int v_size;
	int p;
    while (*a != (*a)->next)
	{
    	v_size = stack_get_size(*a);
		p = (int)v_size - (int)amount;
		if ((*a)->value >= p && (*a)->value != 0)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void sort(t_stack **a, t_stack **b)
{
    while(*b)
	{
        sort_find_smallest(a, b);
	}
}

int is_a_correct(t_stack **a, t_stack *target)
{
	return ((*a)->value > target->value && (*a)->next->value < target->value)
		   || ((*a)->value == 0 && (*a)->next->value < target->value);
}

unsigned int get_amount_moves(t_stack **a, t_stack **b, t_stack *target)
{
	unsigned int size = stack_get_size(*b);
	t_stack *tmp = *a;
	t_stack *tmp2 = *b;
	unsigned int i = 0;

	while (tmp2 != target && i++ < size)
		tmp2 = tmp2->prev;

	if (i > size / 2)
		i = (size / 2) - (i - (size / 2));
	while (!((tmp->value > tmp2->value && tmp->next->value < tmp2->value)
			 || (tmp->value == 0 && tmp->next->value < tmp2->value)))
	{
		if (tmp->value > tmp2->value)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
		i++;
	}
	return (i);
}

void push_target(t_stack **a, t_stack **b, t_stack *target)
{
	unsigned int i = 0;
	unsigned int size = stack_get_size(*b);
	unsigned int dir;
	t_stack *tmp = *b;
	while (tmp != target && i++ < size)
		tmp = tmp->prev;
	dir = i / (size / 2 + 1);

	//rotate to it and push
	if (dir)
	{
		while (!is_a_correct(a, target) && (*a)->value > target->value && *b != target)
			rrotate(a, b);
		while (*b != target)
			rrotate_b(b);
	}
	else
	{
		while (!is_a_correct(a, target) && (*a)->value < target->value && *b != target)
			rotate(a, b);
		while (*b != target)
			rotate_b(b);
	}
	while (!is_a_correct(a, target))
	{
		if ((*a)->value > (*b)->value)
			rrotate_a(a);
		else
			rotate_a(a);
	}
	push_a(a, b);
}

//min inclusive, max exclusive
t_stack *sort_find_smallest(t_stack **a, t_stack **b)
{
	t_stack *smallest_stack;
	unsigned int smallest_opps;
	//    unsigned int smallest_dir;
	unsigned int i;
	unsigned int cost;
	unsigned int size;
	//    t_stack *tmp;
	t_stack *tmp2;

	//    tmp = *a;
	size = stack_get_size(*b);
	i = -1;
	tmp2 = (*b)->next;
	smallest_stack = 0;
	smallest_opps = INT_MAX;
	while (++i < size)
	{
		tmp2 = tmp2->prev;
		cost = get_amount_moves(a, b, tmp2);
		if (cost < smallest_opps)
		{
			smallest_stack = tmp2;
			smallest_opps = cost;
	//            smallest_dir = i / (size / 2 + 1);
		}
	}
	if (!smallest_stack)
		return (0);
	push_target(a, b, smallest_stack);
    //rotate to it and push
//    if (smallest_dir)
//        while (*b != smallest_stack)
//            rrotate_b(b);
//    else
//        while (*b != smallest_stack)
//            rotate_b(b);
//    while (!(((*a)->value > (*b)->value && (*a)->next->value < (*b)->value)
//        || ((*a)->value == 0 && (*a)->next->value < (*b)->value)))
//    {
//        if ((*a)->value > (*b)->value)
//            rrotate_a(a);
//        else
//            rotate_a(a);
//    }
//	push_a(a, b);
    return (smallest_stack);
}
