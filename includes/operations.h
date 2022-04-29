/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:09:25 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/29 13:55:14 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "libft.h"

//returns pointer to pushed t_stack
t_stack	*push_a(t_stack **a, t_stack **b);
t_stack	*push_b(t_stack **a, t_stack **b);

void	rotate(t_stack **a, t_stack **b);
void	rrotate(t_stack **a, t_stack **b);
//returns pointer to top of stack
t_stack	*rotate_a(t_stack **a);
t_stack	*rrotate_a(t_stack **a);
t_stack	*rotate_b(t_stack **b);
t_stack	*rrotate_b(t_stack **a);

//swaps and returns top of stack
t_stack	*swap_a(t_stack **a);
t_stack	*swap_b(t_stack **b);

void	rotate_minimum(t_stack **a, t_stack **b, t_stack *t, unsigned int dir);

#endif
