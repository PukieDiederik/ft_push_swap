/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:43:07 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/26 16:13:13 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack			*input;
	unsigned int	size;

	free(0);
	if (argc == 1)
		return (0);
	input = parse_args(argc - 1, argv + 1);
	if (!input)
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	size = stack_get_size(input);
	if (size == 1)
		return (0);
	stack_index(input);
	if (size == 3)
		generate_3(&input);
	else if (size == 5)
		generate_5(&input);
	else
		generate(&input);
	stack_clear(input);
}
