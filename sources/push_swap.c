/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:59:26 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 12:56:43 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

int	arg_checker(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->max_size)
	{
		j = i;
		while (++j < stack->max_size)
		{
			if (stack->value[i] == stack->value[j])
				return (1);
		}
	}
	return (0);
}

void	sorter(t_stack *stack_a, t_stack *stack_b, char **av)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (i < stack_a->size)
	{
		if (ft_atol(av[j]) == LONG_MAX)
			error(stack_a, stack_b);
		else
			stack_a->value[i] = ft_atol(av[j++]);
		i++;
	}
	if (arg_checker(stack_a))
		error(stack_a, stack_b);
	if (stack_a->max_size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->max_size <= 200)
		sort_100(stack_a, stack_b);
	else
		sort_500(stack_a, stack_b);
}

void	initializer(t_stack *stack_a, t_stack *stack_b, int ac)
{
	int	max_size;

	max_size = ac - 1;
	stack_a->name = 'a';
	stack_b->name = 'b';
	stack_a->size = max_size;
	stack_a->max_size = max_size;
	stack_a->value = ft_calloc(sizeof(int) * stack_a->max_size, sizeof(int));
	if (!stack_a->value)
		return ;
	stack_b->size = 0;
	stack_b->max_size = max_size;
	stack_b->value = ft_calloc(sizeof(int) * stack_b->max_size, sizeof(int));
	if (!stack_b->value)
		return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
	{
		return (0);
	}
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (0);
	initializer(stack_a, stack_b, ac);
	sorter(stack_a, stack_b, av);
	free(stack_a->value);
	free(stack_b->value);
	free(stack_a);
	free(stack_b);
	return (0);
}
