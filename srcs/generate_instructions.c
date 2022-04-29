/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:28:48 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/29 13:53:55 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "operations.h"
#include "generate.h"

void	generate(t_stack **a)
{
	t_stack			*b;
	unsigned int	amount;
	int				*seq;

	b = 0;
	amount = 30;
	seq = get_sequence(a);
	if (stack_get_size(*a) > 150)
		amount = 50;
	qs_partition(a, &b, amount, seq);
	while (b)
	{
		sort_one(a, &b);
	}
	if ((*a)->value < (int)stack_get_size(*a) / 2)
		while ((*a)->value != 0)
			rrotate_a(a);
	else
		while ((*a)->value != 0)
			rotate_a(a);
	free(seq);
}

void	qs_partition(t_stack **a, t_stack **b, unsigned int amount, int *seq)
{
	unsigned int	i;
	unsigned int	v_size;
	int				p;

	i = 0;
	while (*(seq + i))
		i++;
	v_size = stack_get_size(*a);
	while (i < v_size - 1)
	{
		p = (int)v_size - (int)amount;
		if ((*a)->value >= p && (*a)->value != 0
			&& !is_seq(seq, (*a)->value))
			push_b(a, b);
		else
			rotate_a(a);
		v_size = stack_get_size(*a);
	}
}

void	push_target(t_stack **a, t_stack **b, t_stack *target)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	dir;
	t_stack			*tmp;

	i = 0;
	size = stack_get_size(*b);
	tmp = *b;
	while (tmp != target && i++ < size)
		tmp = tmp->prev;
	dir = i / (size / 2 + 1);
	rotate_minimum(a, b, target, dir);
	push_a(a, b);
}

t_stack	*sort_one(t_stack **a, t_stack **b)
{
	t_stack			*smallest_stack;
	unsigned int	smallest_opps;
	unsigned int	i;
	unsigned int	size;
	t_stack			*tmp2;

	size = stack_get_size(*b);
	i = -1;
	tmp2 = (*b)->next;
	smallest_stack = 0;
	smallest_opps = 0xffffffff;
	while (++i < size)
	{
		tmp2 = tmp2->prev;
		if (get_amount_moves(a, b, tmp2) < smallest_opps)
		{
			smallest_stack = tmp2;
			smallest_opps = get_amount_moves(a, b, tmp2);
		}
	}
	if (!smallest_stack)
		return (0);
	push_target(a, b, smallest_stack);
	return (smallest_stack);
}
