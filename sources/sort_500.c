/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:31:51 by miguelro          #+#    #+#             */
/*   Updated: 2023/01/16 18:00:00 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void sort_500(t_stack *stack_a, t_stack *stack_b)
{
	int previous_blocks;
	int block;
	int	block_size;

	block = 0;
	block_size = 75;
	previous_blocks = 0;
	while(!sorted_check(stack_a))
	{
		if (stack_a -> size - block < block_size)
			block += stack_a -> size - block;
		else
			block += block_size;
		//printf("block: %d\nprevious_blocks: %d\n", block, previous_blocks);
		make_block(stack_a, stack_b, block, previous_blocks);
		/* while(stack_a->value[stack_a->max_size-1] != sorted_array(stack_a)[block])
			reverse_rotate_stack(stack_a); */
		sort_block(stack_a, stack_b);
		previous_blocks = block;
		if(!move_to_top(stack_a))
			rotate_stack(stack_a);
	}
}