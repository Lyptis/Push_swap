/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:34:30 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/18 13:35:47 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*get_last(t_stack **stack)
{
	t_stack	*current;

	if(!*stack)
		return (NULL);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

static int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == 45 || str[i] == 43)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_get_input(int size, t_stack **stack, char **argv)
{
	t_stack	*nb;
	t_stack	*last;
	int		i;

	i = 1;
	while (i < size)
	{
		if (ft_check(argv[i]) != 1)
		{
			nb = malloc(sizeof(t_stack));
			nb->val = ft_atoi(argv[i]);
			nb->sim = 0;
			nb->next = 0;
			last = get_last(stack);
			if (!last)
				(*stack) = nb;
			else
				last->next = nb;
		}
		else
		{
			return (1);
			//ft_free();
		}
 		i++;
	}
	return (0);
}