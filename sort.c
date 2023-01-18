/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:16 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/18 17:00:04 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *cursor_a;
	t_stack *cursor_b;
	int i;

	i = 0;
	if (size <= 5)
		ft_printf("To do\n");
	cursor_a = *stack_a;
	//while (is_a_sort(stack_a) == 0 && stack_b)
	//{
		while (i != size / 2)
		{
			if (!((*stack_a)->sim & 1))
			{
				ft_push(stack_a, stack_b, 'a');
				i++;
			}
			if (((*stack_a)->sim & 1))
				ft_rotate(stack_a, 'a');
		}
		while (i > 0)
		{
			ft_push(stack_a, stack_b, 'b');
			i--;
		}

}