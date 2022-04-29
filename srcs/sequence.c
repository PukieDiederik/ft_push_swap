/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:41:06 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/29 13:41:06 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

int	is_seq(int *seq, int val)
{
	int	i;

	i = -1;
	while (*(seq + ++i) != 0)
		if (*(seq + i) == val)
			return (1);
	return (0);
}

int	*get_sequence(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*new_stack;
	int		lowest;
	int		*arr;

	new_stack = 0;
	tmp = *a;
	while (tmp->next->value != 0)
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
