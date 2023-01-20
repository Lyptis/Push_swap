/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:35:54 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/19 10:27:11 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*current;

	if (!*stack)
	{
		ft_printf("stack vide\n");
	}
	else
	{
		current = *stack;
		while (current->next)
		{
			ft_printf("%d ", current->sim);
			current = current->next;
		}
		ft_printf("%d\n", current->sim);
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (ft_putendl_fd("Error", 2), 1);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	*stack_a = 0;
	*stack_b = 0;
	if (ft_get_input(argc, stack_a, argv) == 1)
		return (ft_putendl_fd("Error", 2), 1);
	if (set_indexs(stack_a, argc - 1) == 1)
		return (0);
	print_stack(stack_a);
	ft_sort(stack_a, stack_b, argc - 1);
	print_stack(stack_a);
	print_stack(stack_b);

}
