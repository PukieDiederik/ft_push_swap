/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:41:06 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/29 13:56:07 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(t_stack **a, t_stack **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	ft_putstr_fd("rr\n", 1);
}

void	rrotate(t_stack **a, t_stack **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_putstr_fd("rrr\n", 1);
}

static int	is_a_correct(t_stack **a, t_stack *target)
{
	return (((*a)->value > target->value && (*a)->next->value < target->value)
		|| ((*a)->value == 0 && (*a)->next->value < target->value));
}

void	rotate_minimum(t_stack **a, t_stack **b, t_stack *t, unsigned int dir)
{
	if (dir)
	{
		while (!is_a_correct(a, t)
			&& (*a)->value > t->value && *b != t)
			rrotate(a, b);
		while (*b != t)
			rrotate_b(b);
	}
	else
	{
		while (!is_a_correct(a, t)
			&& (*a)->value < t->value && *b != t)
			rotate(a, b);
		while (*b != t)
			rotate_b(b);
	}
	while (!is_a_correct(a, t))
	{
		if ((*a)->value > (*b)->value)
			rrotate_a(a);
		else
			rotate_a(a);
	}
}
