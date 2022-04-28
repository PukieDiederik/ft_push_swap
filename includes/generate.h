/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:43:17 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/28 15:43:43 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_H
# define GENERATE_H

//partitions stack 'a' to 'b' for quicker sorting
void			qs_partition(t_stack **a, t_stack **b, unsigned int m, int *s);
//sorts 1 element from stack 'b' to 'a'
t_stack			*sort_one(t_stack **a, t_stack **b);
//gets a sequence of numbers that don't need to be pushed
int				*get_sequence(t_stack **a);
//checks if a number is in a sequence
int				is_seq(int *seq, int val);

//gets the amount of moves to get target in the correct
// position in a (assumes target is in b)
unsigned int	get_amount_moves(t_stack **a, t_stack **b, t_stack *target);

#endif
