#include <stdio.h>
#include "stack.h"
#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
    t_stack *input = parse_args(argc - 1, argv + 1);
    int *sorted = stack_to_array(input);
//    unsigned int size;

//    if (!input) {
//        printf("error\n");
//        return (1);
//    }
//    size = get_size_stack(input);
//    quicksort(sorted, 0, size);
//    unsigned int i = -1;
//    while (++i < size)
//    {
//        printf("[%d]: %d\n", i, input->value);
//        input = input->prev;
//    }
    stack_index(input);
//    printf("--------\n");
//
//    i = -1;
//    while (++i < size)
//    {
//        printf("[%d]: %d\n", i, input->value);
//        input = input->prev;
//    }
//    printf("Amount of elements: %u\n", size);
	generate(input);
    free(sorted);
    clear_stack(input);
}