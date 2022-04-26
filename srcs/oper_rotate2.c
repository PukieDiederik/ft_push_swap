/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:03:44 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/26 16:04:21 by drobert-         ###   ########.fr       */
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
