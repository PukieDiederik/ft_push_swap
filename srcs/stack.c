/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:24:18 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/22 12:26:05 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

//creates a new stack element
t_stack	*stack_create(int value)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->next = s;
	s->prev = s;
	s->value = value;
	return (s);
}

//removes (and returns) a stack from the list
t_stack	*stack_remove(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	(tmp)->prev->next = (tmp)->next;
	(tmp)->next->prev = (tmp)->prev;
	(tmp)->prev = s;
	(tmp)->next = s;
	return (s);
}

//deletes/frees the stack element
void	delete_stack(t_stack *s)
{
	free(s);
}

//deletes the entire list of stacks
void	stack_clear(t_stack *s)
{
	t_stack	*temp;

	if (s)
	{
		s->prev->next = 0;
		while (s)
		{
			temp = s->next;
			free(s);
			s = temp;
		}
	}
}

// adds 's' after orig
t_stack	*stack_add(t_stack *orig, t_stack *s)
{
	if (!orig)
		return (s);
	s->next = orig->next;
	s->prev = orig;
	s->next->prev = s;
	orig->next = s;
	return (s);
}
