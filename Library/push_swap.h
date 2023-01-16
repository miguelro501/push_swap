/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:01:52 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 17:35:26 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack{
    int *value;
    int size;
    int max_size;
    char name;
} t_stack;

void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stack_pull, t_stack *stack_push);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
long	ft_atol(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *s, size_t n);
void    sort_3(t_stack *stack);
int     find_smallest_value(t_stack *stack);
int     find_largest_value(t_stack *stack);
int     calculate_path(t_stack *stack, int index);
int     module(int x);
int    move_to_top(t_stack *stack);
void    rotate_path(t_stack *stack, int path);
void    print(t_stack *stack_a, t_stack *stack_b);
void    sort_5(t_stack *stack_a, t_stack *stack_b);
int     *sorted_array(t_stack *stack);
void    sort_100(t_stack *stack_a, t_stack *stack_b);
void	sort_500(t_stack *stack_a, t_stack *stack_b);
int sorted_check(t_stack *stack);
void sort_block(t_stack *stack_a, t_stack *stack_b);
void make_block(t_stack *stack_a, t_stack *stack_b, int block_top, int block_buttom);
void arr_sort(int arr[], int n);
