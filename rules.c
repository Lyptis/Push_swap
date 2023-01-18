/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:03:50 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/18 16:43:48 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*cur;
	t_stack	*cur2;

	cur = *stack;
	if (cur->next && (c == 'a' || c == 'b' || c == 's'))
	{
		if (!(c == 's'))
			ft_printf("s%c\n", c);
		cur2 = cur->next;
		cur->next = cur2->next;
		*stack = cur2;
		cur2->next = cur;
	}
}

void	ft_swaps(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	if (c == 'a')
	{
		cursor_a = *stack_a;
		*stack_a = cursor_a->next;
		cursor_a->next = *stack_b;
		*stack_b = cursor_a;
	}
	else if (c == 'b')
	{
		cursor_b = *stack_b;
		*stack_b = cursor_b->next;
		cursor_b->next = *stack_a;
		*stack_a = cursor_b;
	}
	ft_printf("p%c\n", c);
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*cursor;

	if (c == 'a' || c == 'b' || c == 's')
	{
		cursor = *stack;
		if (cursor->next)
		{
			while (cursor->next)
				cursor = cursor->next;
			cursor->next = *stack;
			*stack = (*stack)->next;
			cursor->next->next = 0;
		}
		if (c != 'r')
			ft_printf("r%c\n", c);
	}
}

void	ft_rotater(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 's');
	ft_rotate(stack_b, 's');
	ft_printf("rr\n");
}