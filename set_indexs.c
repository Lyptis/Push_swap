/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:39 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 15:20:53 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_i_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = *stack;
	while (tmp2)
	{
		if (tmp->val <= tmp2->val)
			tmp2 = tmp2->next;
		else
		{
			tmp = tmp2;
			tmp2 = *stack;
		}
	}
	return (tmp);
}

int	is_a_sort(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*cursor2;

	cursor = *stack;
	if (cursor->next)
		cursor2 = cursor->next;
	else
		return (0);
	while (cursor2)
	{
		if (cursor->val > cursor2->val)
			return (0);
		else
		{
			cursor = cursor2;
			cursor2 = cursor2->next;
		}
	}
	return (1);
}

int	set_indexs(t_stack **stack, int size)
{
	t_stack	*nb;
	t_stack	*cursor;
	int		nbp;

	if (is_a_sort(stack))
		return (1);
	nbp = size - 1;
	while (nbp >= 0)
	{
		nb = ft_i_min(stack);
		cursor = *stack;
		while (cursor)
		{
			if (cursor->val > nb->val && cursor->sim == 0)
			{
				nb = cursor;
				cursor = *stack;
			}
			else
				cursor = cursor->next;
		}
		nb->sim = nbp;
		nbp--;
	}
	return (0);
}
