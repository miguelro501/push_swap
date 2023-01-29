/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:35:37 by marvin            #+#    #+#             */
/*   Updated: 2023/01/27 17:40:48 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	neg = 1;
	value = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (INT_MIN <= value * neg && value * neg <= INT_MAX)
			value = 10 * value + (str[i++] - '0');
		else
			return (LONG_MAX);
	}
	return (value * neg);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
		ptr[i++] = 0;
}

void	*ft_calloc(size_t nitems, size_t size)
{	
	void	*ptr;

	ptr = (void *)malloc(size * nitems);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

int	module(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

/* void print(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("-----------\n");
	for(int i = 0; i < stack_a->max_size; i++){
         ft_printf("%d: %d---%d\n", i, stack_a->value[i], stack_b->value[i]);
    }
	ft_printf("-----------\n");
} */