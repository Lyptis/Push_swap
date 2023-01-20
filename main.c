/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:35:54 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 15:57:46 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack))
	{
		tmp = *stack;
		(*stack) = (*stack)->next;
		free(tmp);
	}
	free(stack);
	return (1);
}

int	ft_free_all(t_stack **stack_a, t_stack **stack_b, int error)
{
	if (error == 0)
	{
		ft_free(stack_a);
		ft_free(stack_b);
		return (0);
	}
	else if (error == 1)
	{
		ft_free(stack_a);
		ft_free(stack_b);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a || argc == 1)
		return (0);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (ft_free(stack_a));
	*stack_a = 0;
	*stack_b = 0;
	if (argc != 2)
	{
		if (ft_get_input(argc, stack_a, argv, 1) == 1)
			return (ft_free_all(stack_a, stack_b, 1));
		if (set_indexs(stack_a, argc - 1) == 1)
			return (ft_free_all(stack_a, stack_b, 0));
	}
	else if (argc <= 2)
	{
		if (ft_get_input_arg(stack_a, argv[1], &argc) == 1)
			return (ft_free_all(stack_a, stack_b, 1));
	}
	ft_sort(stack_a, stack_b, argc - 1);
	return (ft_free_all(stack_a, stack_b, 0));
}
