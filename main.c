/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:45:57 by crepou            #+#    #+#             */
/*   Updated: 2023/05/13 18:51:55 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_arguments(char *argv[], int argc, char ***args)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		(*args) = ft_split(argv[1], ' ');
		while ((*args)[i])
		{
			i++;
		}
		return (i);
	}
	(*args) = NULL;
	return (argc - 1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	ft_initialize(int **a, t_stack_info **stack_info_a, char *argv[], int argc)
{
	char	**args;
	int		number_of_args;
	int		i;
	int		j;

	number_of_args = ft_get_arguments(argv, argc, &args);
	(*a) = (int *)malloc(sizeof(int) * number_of_args);
	i = number_of_args - 1;
	j = 0;
	while (i >= 0)
	{
		if (wrong_arg(j, args, argv))
			return (-1);
		if (args != NULL)
			(*a)[i] = ft_atoi(args[j]);
		else
			(*a)[i] = ft_atoi(argv[j + 1]);
		i--;
		j++;
	}
	(*stack_info_a)->len = number_of_args;
	(*stack_info_a)->size = number_of_args;
	(*stack_info_a)->top = number_of_args - 1;
	if (argc == 2)
		free_args(args);
	return (number_of_args);
}


int	main(int argc, char *argv[])
{
	int				*stack_a;
	t_stack_info	*stack_a_info;
	int				i;
	int				num_of_args;

	if (argc > 1)
	{
		i = 0;
		stack_a_info = (t_stack_info *)malloc(sizeof(t_stack_info));
		num_of_args = ft_initialize(&stack_a, &stack_a_info, argv, argc);
		if (num_of_args < 0 || has_duplicates(stack_a))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		push_swap(stack_a, stack_a_info);
		free(stack_a_info);
		free(stack_a);
		system("leaks push_swap");
	}
	return (0);
}
