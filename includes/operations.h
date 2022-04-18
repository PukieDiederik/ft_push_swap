#ifndef OPPERATIONS_H
#define OPPERATIONS_H

#include "stack.h"
#include "libft.h"

//returns pointer to pushed t_stack
t_stack *push_a(t_stack **a, t_stack **b);
t_stack *push_b(t_stack **a, t_stack **b);

//returns pointer to top of s
t_stack *rotate_a(t_stack **a);
t_stack *rrotate_a(t_stack **a);
t_stack *rotate_b(t_stack **b);
t_stack *rrotate_b(t_stack **a);


#endif
