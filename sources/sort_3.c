/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:18:10 by marvin            #+#    #+#             */
/*   Updated: 2023/01/27 17:21:58 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->value[0] < stack->value[1] && stack->value[1] < stack->value[2])
		return ;
	else if (stack->value[0] < stack->value[1]
		&& stack->value[0] < stack->value[2])
	{
		swap_stack(stack);
		rotate_stack(stack);
	}
	else if (stack->value[0] > stack->value[1]
		&& stack->value[1] > stack->value[2])
	{
		swap_stack(stack);
		reverse_rotate_stack(stack);
	}
	else if (stack->value[0] > stack->value[1]
		&& stack->value[0] > stack->value[2])
		rotate_stack(stack);
	else if (stack->value[0] > stack->value[1]
		&& stack->value[1] < stack->value[2])
		swap_stack(stack);
	else if (stack->value[0] < stack->value[1]
		&& stack->value[1] > stack->value[2])
		reverse_rotate_stack(stack);
}

int	find_smallest_value(t_stack *stack)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (++i < stack->size)
	{
		if (stack->value[i] < stack->value[index])
			index = i;
	}
	return (index);
}

int	find_largest_value(t_stack *stack)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (++i < stack->size)
	{
		if (stack->value[i] > stack->value[index])
			index = i;
	}
	return (index);
}

int	calculate_path(t_stack *stack, int index)
{
	int	path_up;
	int	path_down;

	path_up = index;
	path_down = stack->size - index;
	if (index < stack->size - index)
		return (path_up);
	else
		return (path_down * -1);
}

void	rotate_path(t_stack *stack, int path)
{
	int	i;

	i = -1;
	if (path < 0)
	{
		path *= -1;
		while (++i < path)
			reverse_rotate_stack(stack);
	}
	while (++i < path)
		rotate_stack(stack);
}
