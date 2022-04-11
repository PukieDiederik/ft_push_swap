#include "stack.h"
#include "libft.h"
#include <stdio.h>

int is_valid_arg(char *str);
int has_duplicates(t_stack *s);

t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack;
    int     i;
    char    **split;

    stack = 0;
    while (--argc >= 0)
    {
        split = ft_split(argv[argc], ' ');
        if (!split)
        {
            clear_stack(stack);
            return (0);
        }
        i = 0;
        while (split[i])
        {
            if (is_valid_arg(split[i]))
                stack = add_stack(stack, create_stack(ft_atoi(split[i])));
            else {
                while (split[i])
                    free(split[i++]);
                free(split);
                clear_stack(stack);
                return (0);
            }
            free(split[i++]);
        }
        free(split);
    }
    if (has_duplicates(stack))
	{
		clear_stack(stack);
		return (0);
	}
    return (stack);
}

int ft_strcmp(char *str1, char *str2)
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

//checks if string is all numbers and is within integer range
int is_valid_arg(char *str)
{
    char *tmp;
    unsigned int len;

    tmp = str;
    if (*tmp == '-' || *tmp == '+')
        tmp++;
    while (*tmp == '0'){
        tmp++;
    }
	len = ft_strlen(str) - (tmp - str);
	if (len > 10 || (ft_strlen(str) == 1 && (*str == '+' || *str == '-')))
		return (0);
	while (*tmp)
        if (!ft_isdigit(*tmp++))
            return (0);
    if (*str == '-') {
        if (len == 10 && ft_strcmp(str + ft_strlen(str) - len, "2147483648") > 0)
            return (0);
    }
    else if (len == 10 && ft_strcmp(str + ft_strlen(str) - len, "2147483647") > 0)
            return (0);
    return (1);
}

int has_duplicates(t_stack *s){
	t_stack *current;
	t_stack *next;
	int cur_value;
	unsigned int i;
	unsigned int size;

	if (!s)
		return (0);
	next = s;
	size = get_size_stack(s);
	while (--size > 0)
	{
		cur_value = next->value;
		current = next->next;
		next = next->next;
		i = size;
		while (i-- > 0) {
			if (current->value == cur_value)
				return (1);
			current = current->next;
		}
	}
	return (0);
}