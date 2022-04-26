#include "push_swap.h"
#include "operations.h"


/*
0 1 2
0 2 1
2 1 0
2 0 1
1 0 2
1 2 0

*/
void generate_3(t_stack **a)
{
    if ((*a)->value == 1 && (*a)->prev->value == 0)
        swap_a(a);
    else if ((*a)->value == 2 && (*a)->prev->value == 0)
        rotate_a(a);
    else if ((*a)->value == 1 && (*a)->prev->value == 2)
        rrotate_a(a);
    else if ((*a)->value == 2 && (*a)->prev->value == 1)
    {
        swap_a(a);
        rrotate_a(a);
    }
    else if ((*a)->value == 0 && (*a)->prev->value == 2)
    {
        swap_a(a);
        rotate_a(a);
    }
}