/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:35:37 by marvin            #+#    #+#             */
/*   Updated: 2023/02/06 13:05:40 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

long	ft_atol_aux(int i, long neg, long value, const char *str)
{
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
		if (!('0' <= str[i] && str[i] <= '9'))
			return (LONG_MAX);
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		value = 10 * value + (str[i++] - '0');
		if (!(INT_MIN <= value * neg && value * neg <= INT_MAX))
			return (LONG_MAX);
	}
	if (str[i])
		return (LONG_MAX);
	return (value * neg);
}

long	ft_atol(const char *str)
{
	int		i;
	long	neg;
	long	value;

	i = 0;
	neg = 1;
	value = 0;

	if (!*str)
		return (LONG_MAX);
	return (ft_atol_aux(i, neg, value, str));
}

int	module(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	error(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->value);
	free(stack_b->value);
	free(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	exit(0);
}

/* void print(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("-----------\n");
	for(int i = 0; i < stack_a->max_size; i++){
         ft_printf("%d: %d---%d\n", i, stack_a->value[i], stack_b->value[i]);
    }
	ft_printf("-----------\n");
} */