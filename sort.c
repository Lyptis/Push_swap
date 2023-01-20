/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:16 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/19 10:43:05 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_three_case(t_stack **stack_a)
{
	if ((((*stack_a)->sim) & 1) && !((*stack_a)->next->sim >> 1 & 1))
		ft_swap(stack_a, 'a');
	else if (((*stack_a)->sim >> 1 & 1) && !((*stack_a)->next->sim & 1))
		ft_rotate(stack_a, 'a');
	else if (((*stack_a)->sim & 1))
		ft_rrotate(stack_a, 'a');
	else
	{
		ft_swap(stack_a, 'a');
		ft_three_case(stack_a);
	}
}

static void	ft_five_case(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 4)
		ft_push(stack_a, stack_b, 'a');
	else
	{
		ft_push(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'a');
	}
	ft_three_case(stack_a);
	if (!((*stack_a)->sim & (*stack_b)->sim))
		ft_rotate(stack_a, 'a');
	ft_push(stack_a, stack_b, 'b');
}

static void	ft_special(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_swap(stack_a, 'a');
	else if (size == 3)
		ft_three_case(stack_a);
	else if (size >= 4)
		ft_five_case(stack_a, stack_b, size);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *cursor_a;
	t_stack *cursor_b;
	int i;

	i = 0;
	if (size <= 5)
		ft_special(stack_a, stack_b, size);
	cursor_a = *stack_a;
	/*//while (is_a_sort(stack_a) == 0 && stack_b)
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
		}*/

}
