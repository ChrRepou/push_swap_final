/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:14 by crepou            #+#    #+#             */
/*   Updated: 2023/05/11 18:24:49 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *stack, t_stack_info *stack_info)
{
	int	min_index;
	int	i;

	i = 0;
	min_index = 0;
	while (i <= stack_info->top)
	{
		if (stack[i] < stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	get_min_val(int *stack, t_stack_info *stack_info)
{
	int	min;
	int	i;

	i = 0;
	min = stack[0];
	while (i <= stack_info->top)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	get_max_index(int *stack, t_stack_info *stack_info)
{
	int	max_index;
	int	i;

	i = 0;
	max_index = 0;
	while (i <= stack_info->top)
	{
		if (stack[i] > stack[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	get_max(int *stack, t_stack_info *stack_info)
{
	int	max;
	int	i;

	i = 0;
	max = stack[i];
	while (i <= stack_info->top)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}
