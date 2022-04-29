/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:04:06 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/22 14:07:32 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack			*stack_create(int value); //creates a new stack element
t_stack			*stack_remove(t_stack *s); //removes a stack from the list
void			delete_stack(t_stack *s); //deletes/frees the stack element
void			stack_clear(t_stack *s); //deletes the entire list of stacks
t_stack			*stack_add(t_stack *orig, t_stack *s); // adds 's' after orig
unsigned int	stack_get_size(const t_stack *s); // gets size of 's'
int				*stack_to_array(const t_stack *s); //converts stack to array
int				stack_index(t_stack *s);

#endif