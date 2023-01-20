/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:11:53 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 15:20:44 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	set_zero(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->sim = 0;
		tmp = tmp->next;
	}
	return (1);
}

static t_stack	*ft_get_min(t_stack **stack, int *i)
{
	int		j;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = *stack;
	j = *i;
	while (tmp2)
	{
		if (tmp->val <= tmp2->val)
		{
			j++;
			tmp2 = tmp2->next;
		}
		else
		{
			tmp = tmp2;
			*i = j;
			tmp2 = *stack;
		}
	}
	return (tmp);
}

void	ft_three_case(t_stack **stack_a)
{
	if (is_a_sort(stack_a))
		return ;
	else if ((((*stack_a)->sim) & 1) && !((*stack_a)->next->sim >> 1 & 1))
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

void	ft_five_case(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;
	int		i;
	int		size_cpy;

	i = 0;
	size_cpy = size;
	while (size_cpy > 3)
	{
		tmp = ft_get_min(stack_a, &i);
		while ((*stack_a)->sim != tmp->sim)
		{
			if (i > size_cpy / 2)
				ft_rrotate(stack_a, 'a');
			else
				ft_rotate(stack_a, 'a');
		}
		ft_push(stack_a, stack_b, 'b');
		size_cpy--;
	}
	set_zero(stack_a);
	set_indexs(stack_a, size_cpy);
	ft_three_case(stack_a);
	while (*stack_b)
		ft_push(stack_a, stack_b, 'a');
}
