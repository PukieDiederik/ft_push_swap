#include "libft.h"
#include "push_swap.h"

static int partition(int *arr, int start, int end);

void quicksort(int *arr, int start, int end)
{
    int p;

    if (start >= end || start < 0)
        return ;

    p = partition(arr, start, end);

    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}

static int partition(int *arr, int start, int end)
{
    int pivot;
    int i;
    int j;
    int temp;

    pivot = arr[end - 1];
    i = start;
    j = start - 1;
    while (++j < end - 1) {
        if (arr[j] < pivot) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i++] = temp;
        }
    }
    temp = arr[i];
    arr[i] = arr[end - 1];
    arr[end - 1] = temp;
    return (i);
}