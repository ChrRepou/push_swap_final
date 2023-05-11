/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:59:39 by crepou            #+#    #+#             */
/*   Updated: 2023/05/11 16:25:04 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
extern int	total_operations;

void	sa(int **a, t_stack_info **stack_info_a)
{
	int	temp;

	if ((*stack_info_a)->len > 1)
	{
		temp = (*a)[(*stack_info_a)->top];
		(*a)[(*stack_info_a)->top] = (*a)[(*stack_info_a)->top - 1];
		(*a)[(*stack_info_a)->top - 1] = temp;
		ft_printf("sa\n");
		total_operations++;
	}
}

void	pa(int **a, int **b,
	t_stack_info **stack_info_a, t_stack_info **stack_info_b)
{
	if ((*stack_info_b)->len < 1)
		return ;
	(*stack_info_a)->top += 1;
	(*a)[(*stack_info_a)->top] = (*b)[(*stack_info_b)->top];
	(*stack_info_a)->len++;
	if ((*stack_info_b)->len > 1)
		(*stack_info_b)->top--;
	(*stack_info_b)->len--;
	ft_printf("pa\n");
	total_operations++;
}

void	ra(int **a, t_stack_info **stack_info_a)
{
	int	top_elem;
	int	i;
	int	j;

	if ((*stack_info_a)->len < 2)
		return ;
	top_elem = (*a)[(*stack_info_a)->top];
	i = (*stack_info_a)->top - 1;
	j = (*stack_info_a)->top;
	while (i >= 0)
	{
		(*a)[j] = (*a)[i];
		i--;
		j--;
	}
	(*a)[0] = top_elem;
	ft_printf("ra\n");
	total_operations++;
}

void	rra(int **a, t_stack_info **stack_info_a)
{
	int	last_elem;
	int	k;

	if ((*stack_info_a)->len < 2)
		return ;
	last_elem = (*a)[0];
	k = 0;
	while (k < (*stack_info_a)->top)
	{
		(*a)[k] = (*a)[k + 1];
		k++;
	}
	(*a)[(*stack_info_a)->top] = last_elem;
	ft_printf("rra\n");
	total_operations++;
}

int	is_sorted(int *a, t_stack_info *info)
{
	int	i;
	int	prev_val;

	prev_val = a[0];
	i = 0;
	while (i <= info->top)
	{
		if (prev_val < a[i])
			return (0);
		prev_val = a[i];
		i++;
	}
	return (1);
}
