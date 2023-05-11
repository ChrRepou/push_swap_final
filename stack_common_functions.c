/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_common_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:18:50 by crepou            #+#    #+#             */
/*   Updated: 2023/04/27 12:38:29 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int **a, int **b, t_stack_info **stack_info_a,
		t_stack_info **stack_info_b)
{
	sa(a, stack_info_a);
	sb(b, stack_info_b);
	ft_printf("ss\n");
}

void	rr(int **a, int **b, t_stack_info **stack_info_a,
		t_stack_info **stack_info_b)
{
	ra(a, stack_info_a);
	rb(b, stack_info_b);
	ft_printf("rr\n");
}

void	rrr(int **a, int **b, t_stack_info **stack_info_a,
		t_stack_info **stack_info_b)
{
	rra(a, stack_info_a);
	rrb(b, stack_info_b);
	ft_printf("rrr\n");
}
