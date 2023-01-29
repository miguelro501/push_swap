/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:31:51 by miguelro          #+#    #+#             */
/*   Updated: 2023/01/27 18:04:19 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	make_block(t_stack *stack_a, t_stack *stack_b, int block_top,
		int block_buttom)
{
	int	i;
	int	*array_sorted;

	array_sorted = sorted_array(stack_a);
	i = -1;
	while (++i < stack_a->max_size)
	{
		if (array_sorted[block_buttom] <= stack_a->value[0]
			&& stack_a->value[0] <= array_sorted[block_top - 1])
			push_stack(stack_b, stack_a);
		else
			rotate_stack(stack_a);
	}
	free(array_sorted);
}

void	sort_500(t_stack *stack_a, t_stack *stack_b)
{
	int	previous_blocks;
	int	block;
	int	block_size;

	block = 0;
	block_size = 75;
	previous_blocks = 0;
	while (!sorted_check(stack_a))
	{
		if (stack_a->size - block < block_size)
			block += stack_a->size - block;
		else
			block += block_size;

		make_block(stack_a, stack_b, block, previous_blocks);

		sort_block(stack_a, stack_b);
		previous_blocks = block;
		if (!move_to_top(stack_a))
			rotate_stack(stack_a);
	}
}
