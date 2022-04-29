/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_amount_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:41:06 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/29 13:41:06 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "generate.h"

static unsigned int
	calc_cost(unsigned int adir, unsigned int cost, t_stack *b, t_stack *t);

unsigned int	get_amount_moves(t_stack **a, t_stack **b, t_stack *target)
{
	t_stack			*tmp;
	t_stack			*tmp2;
	int				cost;
	unsigned int	adir;

	tmp = *a;
	tmp2 = target;
	cost = 0;
	adir = 0;
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
	return (calc_cost(adir, cost, *b, target));
}

static unsigned int
	calc_cost(unsigned int adir, unsigned int cost, t_stack *b, t_stack *target)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	dir;

	size = stack_get_size(b);
	i = 0;
	while (b != target && i++ < size)
		b = b->prev;
	dir = i / (size / 2 + 1);
	if (i > size / 2)
		i = (size / 2) - (i - (size / 2));
	if (adir == dir)
	{
		if (cost > i)
			return (cost);
		return (i);
	}
	return (i + cost);
}
