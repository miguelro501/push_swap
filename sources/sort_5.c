/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:07:02 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 17:36:10 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int move_to_top(t_stack *stack)
{
	int	path_large;
	int	path_small;

	path_large = calculate_path(stack, find_largest_value(stack));
	path_small = calculate_path(stack, find_smallest_value(stack));
	if(module(path_large) < module(path_small))
	{
		rotate_path(stack, path_large);
		return 0;
	}
	rotate_path(stack, path_small);
	return 1;
}

void	arrange_smaller(t_stack *stack_a, t_stack *stack_b)
{
	
	if (stack_b->value[0] < stack_a -> value[0] && stack_b->value[1] < stack_a -> value[0])
	{	
		if (stack_b->value[0] < stack_b->value[1])
			rotate_stack(stack_b);
		push_stack(stack_a, stack_b);
		push_stack(stack_a, stack_b);
	}
	else if (stack_b->value[0] > stack_a -> value[stack_a->size - 1] && stack_b->value[1] > stack_a -> value[stack_a->size - 1])
	{	
		if (stack_b->value[0] < stack_b->value[1])
			rotate_stack(stack_b);
		push_stack(stack_a, stack_b);
		push_stack(stack_a, stack_b);
		rotate_stack(stack_a);
		rotate_stack(stack_a);
	}
	else 
	{
		if (stack_b->value[0] > stack_a -> value[0])
			rotate_stack(stack_b);
		push_stack(stack_a, stack_b);
		push_stack(stack_a, stack_b);
		rotate_stack(stack_a);
	}
}

void sort_5(t_stack *stack_a, t_stack *stack_b)
{
	if(stack_a->max_size != stack_b->max_size)
		return;
	if (stack_a->max_size == 3)
	{
		sort_3(stack_a);
		return;
	}
	move_to_top(stack_a);
	push_stack(stack_b, stack_a);
	move_to_top(stack_a);
	push_stack(stack_b, stack_a);
	sort_3(stack_a);
	arrange_smaller(stack_a,stack_b);
}
