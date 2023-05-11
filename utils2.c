/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:02:02 by crepou            #+#    #+#             */
/*   Updated: 2023/05/11 18:29:45 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_is_bigger(int *stack, t_stack_info *stack_info)
{
	int	top_elem;
	int	i;

	top_elem = stack[stack_info->top];
	i = 0;
	while (i < stack_info->top)
	{
		if (top_elem < stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_final_position_of_top(int *stack, t_stack_info *stack_info)
{
	int	i;
	int	top_element;
	int	index;

	top_element = stack[stack_info->top];
	i = stack_info->top;
	index = i;
	while (i >= 0)
	{
		if (top_element > stack[i])
		{
			index = i;
		}
		i--;
	}
	return (stack_info->top - index);
}

int	*simplify_stack(int *stack, t_stack_info *stack_info)
{
	int	i;
	int	j;
	int	*simplified_stack;
	int	max;

	i = 0;
	j = 0;
	max = get_max(stack, stack_info);
	simplified_stack = (int *)malloc(sizeof(int) * stack_info->size);
	if (!simplified_stack)
		return (NULL);
	while (i <= stack_info->top)
	{
		simplified_stack[get_min(stack, stack_info)] = j;
		stack[get_min(stack, stack_info)] = get_max(stack, stack_info) + 1;
		i++;
		j++;
	}
	return (simplified_stack);
}

int	get_zero_index(int *stack, t_stack_info *stack_info)
{
	int	i;
	int	min;

	i = 0;
	min = get_min_val(stack, stack_info);
	while (i <= stack_info->top)
	{
		if (stack[i] == min)
			return (i);
		i++;
	}
	return (0);
}
