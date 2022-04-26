/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:04:33 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/26 16:04:55 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

t_stack	*swap_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->prev;
	(*a)->prev->next = tmp;
	tmp->next->prev = *a;
	tmp->prev = (*a)->prev;
	(*a)->prev = tmp;
	(*a)->next = tmp->next;
	tmp->next = *a;
	ft_putstr_fd("sa\n", 1);
	return (*a);
}

t_stack	*swap_b(t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->prev;
	(*b)->prev->next = tmp;
	tmp->next->prev = *b;
	tmp->prev = (*b)->prev;
	(*b)->prev = tmp;
	(*b)->next = tmp->next;
	tmp->next = *b;
	ft_putstr_fd("sb\n", 1);
	return (*b);
}
