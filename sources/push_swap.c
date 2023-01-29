/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:59:26 by marvin            #+#    #+#             */
/*   Updated: 2023/01/27 17:57:18 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

void	initializer(t_stack *stack_a, t_stack *stack_b, char **av)
{
	int		j;
	int		i;

	i = 0;
		j = 1;

	while (i < stack_a->size)
	{
		if (ft_atol(av[j]) == LONG_MAX)
		{
			ft_printf("Error");
			return ;
		}
		else
			stack_a->value[i] = ft_atol(av[j++]);
		i++;
	}
	if (stack_a->max_size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->max_size <= 200)
		sort_100(stack_a, stack_b);
	else
		sort_500(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		max_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	max_size = ac - 1;
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (0) ;
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (0) ;
	stack_a->name = 'a';
	stack_b->name = 'b';
	stack_a->size = max_size;
	stack_a->max_size = max_size;
	stack_a->value = ft_calloc(sizeof(int) * stack_a->max_size, sizeof(int));
	if (!stack_a ->value)
		return (0) ;
	stack_b->size = 0;
	stack_b->max_size = max_size;
	stack_b->value = ft_calloc(sizeof(int) * stack_b->max_size, sizeof(int));
	if (!stack_b ->value)
		return (0) ;
	initializer(stack_a, stack_b, av);
	free(stack_a->value);
	free(stack_b->value);
	free(stack_a);
	free(stack_b);
	return (0);
}
