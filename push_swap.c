/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:48:47 by crepou            #+#    #+#             */
/*   Updated: 2023/05/13 13:49:09 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	total_operations = 0;

void	printf_stack(int *a, t_stack_info *info)
{
	int	i;

	i = info->top;
	while (i >= 0)
	{
		ft_printf("%d\n", a[i]);
		i--;
	}
}

int	push_swap(int *a, t_stack_info *stack_info_a)
{
	int				*b;
	t_stack_info	*stack_info_b;
	int				*c;

	if (is_sorted(a, stack_info_a))
		return (1);
	b = (int *)malloc(sizeof(int) * stack_info_a->size);
	stack_info_b = (t_stack_info *)malloc(sizeof(t_stack_info));
	stack_info_b->len = 0;
	stack_info_b->size = stack_info_a->size;
	stack_info_b->top = 0;
	if (stack_info_a->size == 3)
		sort_3(&a, &stack_info_a);
	else if (stack_info_a->size > 3 && stack_info_a->size < 6)
		small_sort(&a, stack_info_a, &b, stack_info_b);
	else
	{
		c = a;
		a = simplify_stack(a, stack_info_a);
		free(c);
		big_sort(&a, stack_info_a, &b, stack_info_b);
	}
	free(b);
	free(stack_info_b);
	return (0);
}
