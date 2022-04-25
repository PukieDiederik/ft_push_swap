#include "push_swap.h"
#include "stack.h"
#include "limits.h"
#include "operations.h"

void qs_partition(t_stack **a, t_stack **b, unsigned int amount, int *sequence);
void sort(t_stack **a, t_stack **b);
t_stack *sort_find_smallest(t_stack **a, t_stack **b);
int *get_sequence(t_stack **a);
int is_seq(int *seq, int val);

void generate(t_stack **a)
{
	t_stack *b = 0;
	unsigned int amount = 30;
	int *seq = get_sequence(a);

    if (stack_get_size(*a) > 150)
		amount = 50;
    qs_partition(a, &b, amount, seq);
	sort(a, &b);
	if ((*a)->value < (int)stack_get_size(*a) / 2)
		while ((*a)->value != 0)
        	rrotate_a(a);
	else
		while ((*a)->value != 0)
			rotate_a(a);
	free(seq);
}

int is_seq(int *seq, int val)
{
	int i;

	i = -1;
	while (*(seq + ++i) != 0)
		if (*(seq + i) == val)
			return (1);
	return (0);
}

int *get_sequence(t_stack **a)
{
	t_stack *tmp;
	t_stack *new_stack;
	int lowest;
	int *arr;

	new_stack = 0;
	tmp = *a;
	while(tmp->next->value != 0)
		tmp = tmp->next;
	lowest = 0;
	while (tmp->value != 0)
	{
		if (tmp->value > lowest)
		{
			new_stack = stack_add(new_stack, stack_create(tmp->value));
			lowest = tmp->value;
		}
		tmp = tmp->prev;
	}
	stack_add(new_stack, stack_create(0));
	arr = stack_to_array(new_stack);
	stack_clear(new_stack);
	return (arr);
}

void qs_partition(t_stack **a, t_stack **b, unsigned int amount, int *sequence)
{
	unsigned int i;
    unsigned int v_size;
	int p;
	i = 0;
	while (*(sequence + i))
		i++;
	v_size = stack_get_size(*a);
    while (i < v_size - 1)
	{
		p = (int)v_size - (int)amount;
		if ((*a)->value >= p && (*a)->value != 0
			&& !is_seq(sequence, (*a)->value))
			push_b(a, b);
		else
			rotate_a(a);
		v_size = stack_get_size(*a);
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
	int i = 0;
	int cost = 0;
	unsigned int dir;
	unsigned int adir = 0;

	while (tmp2 != target && i++ < (int)size)
		tmp2 = tmp2->prev;

	dir = i / (size / 2 + 1);
	if (i > (int)size / 2)
		i = ((int)size / 2) - (i - ((int)size / 2));
	while (!((tmp->value > tmp2->value && tmp->next->value < tmp2->value)
			 || (tmp->value == 0 && tmp->next->value < tmp2->value)))
	{
		if (tmp->value > tmp2->value)
		{
			tmp = tmp->next;
			adir = 1;
		}
		else
			tmp = tmp->prev;
		cost++;
	}
	if (adir == dir)
	{
		if (cost > i)
			return (cost);
		return (i);
	}
	return (i + cost);
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
	unsigned int i;
	unsigned int cost;
	unsigned int size;
	t_stack *tmp2;

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
		}
	}
	if (!smallest_stack)
		return (0);
	push_target(a, b, smallest_stack);
    return (smallest_stack);
}
