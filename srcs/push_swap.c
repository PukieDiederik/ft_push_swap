#include "stack.h"
#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
    t_stack *input = parse_args(argc - 1, argv + 1);
    if (!input)
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
    unsigned int size = stack_get_size(input);
    stack_index(input);
    if (size == 3)
		generate_3(&input);
    else
		generate(&input);
    stack_clear(input);
}