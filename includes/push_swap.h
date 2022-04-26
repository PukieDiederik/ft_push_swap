/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:06:45 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/26 16:06:56 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

t_stack	*parse_args(int argc, char **argv);
void	quicksort(int *arr, int start, int end);
void	generate(t_stack **a);
void	generate_3(t_stack **a);
void	generate_5(t_stack **a);

#endif