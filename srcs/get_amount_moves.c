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

unsigned int	get_amount_moves(t_stack **a, t_stack **b, t_stack *target)
{
	unsigned int	size;
	t_stack			*tmp;
	t_stack			*tmp2;
	int				i;
	int				cost;
	unsigned int	dir;
	unsigned int	adir;

	size = stack_get_size(*b);
	tmp = *a;
	tmp2 = *b;
	i = 0;
	cost = 0;
	adir = 0;
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