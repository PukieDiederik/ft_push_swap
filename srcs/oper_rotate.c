/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:03:21 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/26 16:04:23 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//returns pointer to top of stack
t_stack	*rotate_a(t_stack **a)
{
	*a = (*a)->prev;
	ft_putstr_fd("ra\n", 1);
	return (*a);
}

t_stack	*rrotate_a(t_stack **a)
{
	*a = (*a)->next;
	ft_putstr_fd("rra\n", 1);
	return (*a);
}

t_stack	*rotate_b(t_stack **b)
{
	*b = (*b)->prev;
	ft_putstr_fd("rb\n", 1);
	return (*b);
}

t_stack	*rrotate_b(t_stack **b)
{
	*b = (*b)->next;
	ft_putstr_fd("rrb\n", 1);
	return (*b);
}
