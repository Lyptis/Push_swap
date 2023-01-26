/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:34:30 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/26 11:25:33 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*get_last(t_stack **stack)
{
	t_stack	*current;

	if (!*stack)
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
		if (str[i] == 45 || str[i] == 43)
		{
			i++;
			if ((str[i] == 45 && str[i] == 43) || i >= 2)
				return (1);
		}
		else if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (1);
	}
	if (str[i - 1] == 43 || str[i - 1] == 45)
		return (1);
	return (0);
}

t_stack	*ft_create(char *str)
{
	t_stack	*nb;

	nb = malloc(sizeof(t_stack));
	if (!nb)
		return (NULL);
	if (ft_strlen(str) >= 10 && ft_atoi(str) == -1)
	{
		free(nb);
		return (NULL);
	}
	else
		nb->val = ft_atoi(str);
	nb->sim = 0;
	nb->next = 0;
	return (nb);
}

int	ft_get_input(int size, t_stack **stack, char **argv, int i)
{
	t_stack	*nb;
	t_stack	*last;

	while (i < size)
	{
		if (ft_check(argv[i]) != 1)
		{
			nb = ft_create(argv[i]);
			if (!nb)
				return (1);
			last = get_last(stack);
			if (!last)
				(*stack) = nb;
			else
				last->next = nb;
		}
		else
			return (1);
		i++;
	}
	if (ft_check_same(stack))
		return (1);
	return (0);
}

int	ft_get_input_arg(t_stack **stack, char *str, int *size)
{
	char	**input;
	int		i;

	i = 0;
	if (*size < 2)
		return (1);
	input = ft_split(str, ' ');
	if (!input)
		return (1);
	while (input[i])
		i++;
	if ((ft_get_input(i, stack, input, 0) == 1))
	{
		ft_free_input(input);
		return (1);
	}
	ft_free_input(input);
	set_indexs(stack, i);
	*size = i + 1;
	return (0);
}
