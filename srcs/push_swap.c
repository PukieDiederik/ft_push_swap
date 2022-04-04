#include <stdio.h>
#include "stack.h"
#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
    t_stack *input = parse_args(argc - 1, argv + 1);
    unsigned int size;

    if (!input) {
        printf("error\n");
        return (1);
    }

    size = get_size_stack(input);

    printf("Amount of elements: %u\n", size);
}