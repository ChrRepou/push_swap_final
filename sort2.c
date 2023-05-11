/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:29:38 by crepou            #+#    #+#             */
/*   Updated: 2023/05/11 16:10:40 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_binary_digits(int num)
{
	int	b_digits;
	int	i;

	i = 2;
	b_digits = 1;
	if (num < 2)
		return (1);
	if (num == 2)
		return (2);
	while (i < num)
	{
		i *= 2;
		b_digits++;
	}
	return (b_digits);
}

void	big_sort(int **stack, t_stack_info *stack_info, int **stack_b, t_stack_info *info_b)
{
	int			max_b_digits;
	int			i;
	int			j;
	int			k;
	u_int32_t	mask;

	max_b_digits = count_binary_digits(get_max(*stack, stack_info));
	i = 0;
	j = stack_info->top;
	while (i < max_b_digits)
	{
		j = stack_info->top;
		while (j-- >= 0)
		{
			mask = (*stack)[stack_info->top] >> i;
			if ((mask & 1))
				ra(stack, &stack_info);
			else
				pb(stack_b, stack, &info_b, &stack_info);
		}
		k = info_b->top - 1;
		while (k-- >= 0)
			pa(stack, stack_b, &stack_info, &info_b);
		i++;
	}
}
