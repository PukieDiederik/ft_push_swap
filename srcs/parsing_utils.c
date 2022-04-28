/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:19:50 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/28 13:04:45 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	is_valid_arg(char *str);
int	has_duplicates(t_stack *s);

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	char	**split;

	stack = 0;
	while (--argc >= 0)
	{
		split = ft_split(argv[argc], ' ');
		if (!split || !split[0])
		{
			free(split);
			stack_clear(stack);
			return (0);
		}
		i = 1;
		while (split[i] != 0)
			i++;
		while (--i >= 0)
		{
			if (is_valid_arg(split[i]))
				stack = stack_add(stack, stack_create(ft_atoi(split[i])));
			else
			{
				while (i >= 0)
					free(split[i--]);
				free(split);
				stack_clear(stack);
				return (0);
			}
			free(split[i]);
		}
		free(split);
	}
	if (has_duplicates(stack))
	{
		stack_clear(stack);
		return (0);
	}
	return (stack);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if ((*str1) - (*str2))
			return ((*str1) - (*str2));
		str1++;
		str2++;
	}
	return ((*str1) - (*str2));
}

//Checks if the string is under the max/min int
// int	check_under_max(char *str, int len)
// {
// 	if (*str == '-')
// 	{
// 		if (len == 10
// 			&& ft_strcmp(str + ft_strlen(str) - len, "2147483648") > 0)
// 			return (0);
// 	}
// 	else if (len == 10
// 		&& ft_strcmp(str + ft_strlen(str) - len, "2147483647") > 0)
// 		return (0);
// 	return (1);
// }

//checks if string is all numbers and is within integer range
int	is_valid_arg(char *str)
{
	char			*tmp;
	unsigned int	len;

	tmp = str;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	if (!tmp)
		return (0);
	while (*tmp == '0')
		tmp++;
	len = ft_strlen(str) - (tmp - str);
	if (len > 10 || (ft_strlen(str) == 1 && (*str == '+' || *str == '-')))
		return (0);
	while (*tmp)
		if (!ft_isdigit(*tmp++))
			return (0);
	if (*str == '-' && len == 10
		&& ft_strcmp(str + ft_strlen(str) - len, "2147483648") > 0)
		return (0);
	else if (*str != '-' && len == 10
		&& ft_strcmp(str + ft_strlen(str) - len, "2147483647") > 0)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *s)
{
	t_stack			*current;
	t_stack			*next;
	int				cur_value;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (0);
	next = s;
	size = stack_get_size(s);
	while (--size > 0)
	{
		cur_value = next->value;
		current = next->next;
		next = next->next;
		i = size;
		while (i-- > 0)
		{
			if (current->value == cur_value)
				return (1);
			current = current->next;
		}
	}
	return (0);
}
