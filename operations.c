/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:24:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 11:24:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_stack(t_stack *stack) {
    if (stack->size < 2) 
        return;
    int temp = stack->value[0];
    stack->value[0] = stack->value[1];
    stack->value[1] = temp;
	printf("S%c\n", stack->name);
}

//pushes the value on top of stack push to top of stack pull
void push_stack(t_stack *stack_pull, t_stack *stack_push) {
    int	i;

    if(stack_pull->max_size == stack_pull->size)
        return;
    stack_pull->size++;
	i = stack_pull->size;
	while(--i >= 0 )
	{
        stack_pull->value[i] = stack_pull->value[i - 1];
	}
	stack_pull->value[0] = stack_push->value[0];
	stack_push->size--;
	i = -1;
    while(++i < stack_push->size)
	{
        stack_push->value[i] = stack_push->value[i + 1];
	}
	while(i < stack_push -> max_size)
		stack_push->value[i++] = 0;
	printf("P%c\n", stack_pull->name);
}

void reverse_rotate_stack(t_stack *stack) {
    int temp = stack->value[stack->size - 1];
    for (int i = stack->size - 1; i > 0; i--) {
        stack->value[i] = stack->value[i - 1];
    }
    stack->value[0] = temp;
	printf("RR%c\n", stack->name);
}

void rotate_stack(t_stack *stack) {
    int temp = stack->value[0];
    for (int i = 0; i < stack->size-1; i++) {
        stack->value[i] = stack->value[i + 1];
    }
    stack->value[stack->size - 1] = temp;
	printf("R%c\n", stack->name);
}
