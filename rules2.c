/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:33:36 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 13:08:20 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack	*cursor;

	if (c == 'a' || c == 'b' || c == 's')
	{
		cursor = *stack;
		if (c != 's')
			ft_printf("rr%c\n", c);
		if (cursor->next && cursor->next)
		{
			while (cursor->next->next)
				cursor = cursor->next;
			cursor->next->next = *stack;
			*stack = cursor->next;
			cursor->next = NULL;
		}
	}
}

void	ft_rrotater(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a, 's');
	ft_rrotate(stack_b, 's');
	ft_printf("rrr\n");
}

void	ft_push_all(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (c == 'b')
	{
		while ((*stack_a))
			ft_push(stack_a, stack_b, 'b');
	}
	else
	{
		while ((*stack_b))
			ft_push(stack_a, stack_b, 'a');
	}
}
