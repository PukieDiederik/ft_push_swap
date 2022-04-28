/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:15:46 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/28 13:30:42 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

t_stack	*sort_one(t_stack **a, t_stack **b);

void	generate_3(t_stack **a)
{
	if ((*a)->value == 1 && (*a)->prev->value == 0)
		swap_a(a);
	else if ((*a)->value == 2 && (*a)->prev->value == 0)
		rotate_a(a);
	else if ((*a)->value == 1 && (*a)->prev->value == 2)
		rrotate_a(a);
	else if ((*a)->value == 2 && (*a)->prev->value == 1)
	{
		swap_a(a);
		rrotate_a(a);
	}
	else if ((*a)->value == 0 && (*a)->prev->value == 2)
	{
		swap_a(a);
		rotate_a(a);
	}
}

void	generate_5(t_stack **a)
{
	t_stack	*b;

	if ((*a)->value == 0 && (*a)->prev->value == 1
		&& (*a)->prev->prev->value == 2
		&& (*a)->next->value == 4 && (*a)->next->next->value == 3)
		return ;
	b = 0;
	if ((*a)->value == 0)
		rotate_a(a);
	push_b(a, &b);
	if ((*a)->value == 0)
		rotate_a(a);
	push_b(a, &b);
	generate_3(a);
	sort_one(a, &b);
	sort_one(a, &b);
}
