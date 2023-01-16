/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:59:26 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 17:33:27 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/push_swap.h"


int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    int max_size = ac - 1;
    t_stack *stack_a = ft_calloc(1, sizeof(t_stack));
    t_stack *stack_b = ft_calloc(1, sizeof(t_stack));

    stack_a ->size = max_size;
    stack_a ->max_size = max_size;
    stack_a ->value = ft_calloc(sizeof(int) *  stack_a ->max_size, sizeof(int));
    stack_a ->name = 'a';

    stack_b ->name = 'b';
    stack_b ->size = 0;
    stack_b ->max_size = max_size;
    stack_b ->value = ft_calloc(sizeof(int) *  stack_b ->max_size, sizeof(int));
    int j = 1;

    for (int i = 0; i < stack_a -> size; i++){
        if (ft_atol(av[j]) == LONG_MAX){
            printf("numero invalido");
            return 0;
        }
        else
            stack_a->value[i] = ft_atol(av[j++]);
    }

    /* swap_stack(stack_a);
    push_stack(stack_b, stack_a);
    push_stack(stack_b, stack_a);
    push_stack(stack_a, stack_b);
    push_stack(stack_a, stack_b); */
    //print(stack_a, stack_b);
    //rotate_stack(stack_a);
    //reverse_rotate_stack(stack_a);
    //sort_3(stack_a);
    //print(stack_a,stack_b);
    //sort_5(stack_a, stack_b);
	if (stack_a->max_size <= 5)
		sort_5(stack_a,stack_b);
    else if (stack_a->max_size <= 200)
		sort_100(stack_a, stack_b);
	else
		sort_500(stack_a, stack_b);
    //print(stack_a,stack_b);
    //printf("%d ", calculate_median(stack_a));

    //printf("1: %d\n2: %d\n",calculate_path(stack_a, find_largest_value(stack_a)), calculate_path(stack_a, find_smallest_value(stack_a)));
    free (stack_a);
    free (stack_b);
    return 0;
}

