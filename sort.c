/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:28:16 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 15:58:29 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (is_a_sort(stack_a) || size < 2)
		return ;
	if (size <= 5)
		ft_special(stack_a, stack_b, size);
	while (b <= 8)
	{
		if (is_a_sort(stack_a))
			return ;
		i = 0;
		while (i < size)
		{
			if (!((*stack_a)->sim >> b & 1))
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
			i++;
		}
		ft_push_all(stack_a, stack_b, 'a');
		b++;
	}
}
