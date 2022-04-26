/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <drobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:17:42 by drobert-          #+#    #+#             */
/*   Updated: 2022/04/26 16:18:32 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	partition(int *arr, int start, int end);

void	quicksort(int *arr, int start, int end)
{
	int	p;

	if (start >= end || start < 0)
		return ;
	p = partition(arr, start, end);
	quicksort(arr, start, p);
	quicksort(arr, p + 1, end);
}

static int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[end - 1];
	i = start;
	j = start - 1;
	while (++j < end - 1)
	{
		if (arr[j] <= pivot)
		{
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
