/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:13 by marvin            #+#    #+#             */
/*   Updated: 2023/01/12 12:44:43 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

/* copy the stack to an array, arrange de array in order, calculate de median x times,
pass blocks to stackb, aplly insertion sort */

void quicksort(int arr[], int low, int high)
{
    int pivot;
	int	i;
	int j;
	int temp;

    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= high)
                i++;
            while (arr[j] > arr[pivot] && j >= low)
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

int *sorted_array(t_stack *stack)
{
	int *arr;
	int	i;

	i = -1;
	arr = malloc(sizeof(int) * stack->max_size);
	while (++i < stack->max_size)
		arr[i] = stack ->value[i];
	quicksort(arr, 0, stack->max_size);
	return arr;
}

void make_block(t_stack *stack_a, t_stack *stack_b, int block_top, int block_buttom)
{
	int	i;

	i = -1;
	while(++i < stack_a -> max_size)
	{
		if(sorted_array(stack_a)[block_buttom] <= stack_a->value[i] && stack_a->value[i] < sorted_array(stack_a)[block_top])
			push_stack(stack_b, stack_a);
	}
}

void sort_block(t_stack *stack_a, t_stack *stack_b)
{
	int	toggle;
	while(stack_b->size > 0)
	{
		toggle = move_to_top(stack_b);
		push_stack(stack_a, stack_b);
		if(toggle == 1)
			rotate_stack(stack_a);
	}
}

int sorted_check(t_stack *stack)
{
	int	i;
	int j;

	i = -1;
	while(++i < stack->size)
	{
		j = i;
		while(++j < stack->size)
		{
			if(stack->value[i] > stack->value[j])
				return 0;

		}
	}
	return 1;
}

void sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int	block_top;

	block_top = 20;
	while(!sorted_check(stack_a))
	{
		make_block(stack_a, stack_b,block_top, block_top - 20);
		sort_block(stack_a, stack_b);
		block_top += 20;
		if(!move_to_top(stack_a))
			rotate_stack(stack_a);
	}
}