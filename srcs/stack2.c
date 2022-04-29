/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:20:17 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/22 12:23:57 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

unsigned int	stack_get_size(const t_stack *s)
{
	t_stack	*current;
	int		size;

	if (!s)
		return (0);
	current = s->next;
	size = 1;
	while (current != s)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	*stack_to_array(const t_stack *s)
{
	int				*arr;
	unsigned int	size;
	unsigned int	i;

	if (!s)
		return (0);
	size = stack_get_size(s);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = -1;
	while (++i < size)
	{
		arr[i] = s->value;
		s = s->prev;
	}
	return (arr);
}

int	stack_index(t_stack *s)
{
	int	size;
	int	i;
	int	j;
	int	*sorted;

	size = (int)stack_get_size(s);
	sorted = stack_to_array(s);
	if (!sorted)
		return (0);
	quicksort(sorted, 0, size);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j < size && s->value != sorted[j])
			j++;
		s->value = j;
		s = s->next;
	}
	free(sorted);
	return (1);
}
