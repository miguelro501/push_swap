/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:24:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/27 18:08:43 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->value[0];
	stack->value[0] = stack->value[1];
	stack->value[1] = temp;
	ft_printf("s%c\n", stack->name);
}

//pushes the value on top of stack push to top of stack pull
void	push_stack(t_stack *stack_pull, t_stack *stack_push)
{
	int	i;

	if (stack_pull->max_size == stack_pull->size)
		return ;
	stack_pull->size++;
	i = stack_pull->size;
	while (--i > 0)
	{
		stack_pull->value[i] = stack_pull->value[i - 1];
	}
	stack_pull->value[0] = stack_push->value[0];
	stack_push->size--;
	i = -1;
	while (++i < stack_push->size)
	{
		stack_push->value[i] = stack_push->value[i + 1];
	}
	while (i < stack_push->max_size)
		stack_push->value[i++] = 0;
	ft_printf("p%c\n", stack_pull->name);
}

void	reverse_rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->value[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->value[i] = stack->value[i - 1];
		i--;
	}
	stack->value[0] = temp;
	ft_printf("rr%c\n", stack->name);
}

void	rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->value[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->value[i] = stack->value[i + 1];
		i++;
	}
	stack->value[stack->size - 1] = temp;
	ft_printf("r%c\n", stack->name);
}
