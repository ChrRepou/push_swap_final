/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:37 by crepou            #+#    #+#             */
/*   Updated: 2023/05/11 19:09:03 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_identify(int *smallest, int *biggest, int *a)
{
	int	i;

	i = 0;
	(*smallest) = 0;
	(*biggest) = 0;
	while (i < 3)
	{
		if (a[i] < a[(*smallest)])
			(*smallest) = i;
		else if (a[i] > a[(*biggest)])
			(*biggest) = i;
		i++;
	}
}

void	sort_3(int **stack_a, t_stack_info **stack_a_info)
{
	int	smallest;
	int	biggest;

	if (is_sorted(*stack_a, *stack_a_info))
		return ;
	sort_identify(&smallest, &biggest, *stack_a);
	if (smallest == 1 && biggest == 0)
		sa(stack_a, stack_a_info);
	else if (smallest == 1 && biggest == 2)
		ra(stack_a, stack_a_info);
	else if (smallest == 0 && biggest == 2)
	{
		sa(stack_a, stack_a_info);
		rra(stack_a, stack_a_info);
	}
	else if (smallest == 2 && biggest == 1)
	{
		sa(stack_a, stack_a_info);
		ra(stack_a, stack_a_info);
	}
	else
		rra(stack_a, stack_a_info);
}

void	comp_sort(int **stack, t_stack_info *stack_info, int index)
{
	int	i;

	i = index - 1;
	while (i > 0)
	{
		sa(stack, &stack_info);
		ra(stack, &stack_info);
		i--;
	}
	sa(stack, &stack_info);
	i = index - 1;
	while (i > 0)
	{
		rra(stack, &stack_info);
		i--;
	}
}

void	sort_stack(int **stack, t_stack_info *stack_a_info)
{
	int	index;

	if (is_sorted(*stack, stack_a_info))
		return ;
	else if (top_is_bigger(*stack, stack_a_info))
	{
		ra(stack, &stack_a_info);
		return ;
	}
	index = get_final_position_of_top(*stack, stack_a_info);
	if (index == 1)
		sa(stack, &stack_a_info);
	else if (index > 1)
		comp_sort(stack, stack_a_info, index);
}

void	small_sort(int **stack_a, t_stack_info *stack_a_info, int **stack_b,
		t_stack_info *stack_b_info)
{
	int	zero_index;

	zero_index = get_zero_index(*stack_a, stack_a_info);
	if (zero_index >= stack_a_info->len / 2)
	{
		while(get_zero_index(*stack_a, stack_a_info) != stack_a_info->top)
			ra(stack_a, &stack_a_info);
	}
	else
	{
		while(get_zero_index(*stack_a, stack_a_info) != stack_a_info->top)
			rra(stack_a, &stack_a_info);
	}
	pb(stack_b, stack_a, &stack_b_info, &stack_a_info);
	if (stack_a_info->size > 4)
		pb(stack_b, stack_a, &stack_b_info, &stack_a_info);
	sort_3(stack_a, &stack_a_info);
	pa(stack_a, stack_b, &stack_a_info, &stack_b_info);
	sort_stack(stack_a, stack_a_info);
	if (stack_a_info->size > 4)
	{
		pa(stack_a, stack_b, &stack_a_info, &stack_b_info);
		sort_stack(stack_a, stack_a_info);
	}
}
