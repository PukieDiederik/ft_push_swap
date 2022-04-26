#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "stack.h"

t_stack *parse_args(int argc, char **argv);
void quicksort(int *arr, int start, int end);
void generate(t_stack **a);
void generate_3(t_stack **a);
void generate_5(t_stack **a);

#endif