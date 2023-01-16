/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:16:13 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 17:43:18 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

/* copy the stack to an array, arrange de array in order, calculate de median x times,
pass blocks to stackb, aplly insertion sort */

void arr_sort(int arr[], int n)
{
	int i; 
	int j;
	int min_idx;
	int	tmp;

	for (i = 0; i < n - 1; i++) {

		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		tmp = arr[min_idx];
		arr[min_idx]= arr[i];
		arr[i] = tmp;
	}
}

int *sorted_array(t_stack *stack)
{
	int *arr;
	int	i;

	i = -1;
	arr = malloc(sizeof(int) * stack->max_size );
	while (++i <= stack->max_size)
		arr[i] = stack -> value[i];
	arr_sort(arr, stack->max_size);
	return arr;
}

void make_block(t_stack *stack_a, t_stack *stack_b, int block_top, int block_buttom)
{
	int	i;
	int *array_sorted;

	array_sorted = sorted_array(stack_a);
	i = -1;
	while(++i < stack_a -> max_size)
	{
		/* for(int k = 0; k < stack_a->max_size;k++)
			printf("%d ", array_sorted[k]); */
		//printf("\n%d %d %d\n", array_sorted[block_buttom], stack_a->value[0], array_sorted[block_top-1]);
		if(array_sorted[block_buttom] <= stack_a->value[0] && stack_a->value[0] <= array_sorted[block_top - 1])		
				push_stack(stack_b, stack_a);
		else
			rotate_stack(stack_a);
	}
}

void sort_block(t_stack *stack_a, t_stack *stack_b)
{
	int	toggle;
	while(stack_b->size > 0)
	{
		//print(stack_a,stack_b);
		toggle = move_to_top(stack_b);
		push_stack(stack_a, stack_b);
		if(toggle == 1)
			rotate_stack(stack_a);
	}
	/* while(!move_to_top(stack_a))
			rotate_stack(stack_a); */
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
	int previous_blocks;
	int block;
	int	block_size;

	block = 0;
	block_size = 50;
	previous_blocks = 0;
	while(!sorted_check(stack_a))
	{
		if (stack_a -> size - block < block_size)
			block += stack_a -> size - block;
		else
			block += block_size;
		//printf("block: %d\nprevious_blocks: %d\n", block, previous_blocks);
		make_block(stack_a, stack_b, block, previous_blocks);
		sort_block(stack_a, stack_b);
/* 		while(stack_a->value[stack_a->max_size-1] != sorted_array(stack_a)[block])
			reverse_rotate_stack(stack_a); */
		previous_blocks = block;
		if(!move_to_top(stack_a))
			rotate_stack(stack_a);
	}
}