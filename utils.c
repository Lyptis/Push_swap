/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:39 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/16 15:52:18 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_pile	*ft_i_min(t_pile *input)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = input;
	tmp2 = input;
	while (tmp2->next)
	{
		if (tmp->val <= tmp2->val)
			tmp2 = tmp2->next;
		else
		{
			tmp = tmp2;
			tmp2 = input;
		}
	}
	return (tmp);
}

void	*ft_cpy(t_pile *input, t_pile *cpy, int size)
{
	t_pile	*cpy_tmp;
	t_pile	*tmp;
	t_pile	*tmp2;
	int		nbp;

	nbp = 1;
	tmp = input;
	while (nbp <= size)
	{
		tmp2 = ft_i_min(input);
		cpy_tmp = cpy;
		tmp = input;
		while (tmp->next)
		{
			if (cpy_tmp->val == 0 && tmp->val > tmp2->val)
			{
				printf("%d\n", cpy_tmp->val);
				tmp2 = tmp;
				tmp = input;
				cpy_tmp = cpy;
			}
			else
			{
				tmp = tmp->next;
				if (!cpy_tmp->next)
					cpy_tmp->next = malloc(sizeof(t_pile));
				cpy_tmp = cpy_tmp->next;
			}
		}
		cpy_tmp->val = nbp;
		nbp++;
	}
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57 || str[i] == 45 || str[i] == 43)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_a_sort(t_pile *input)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = input;
	if (input->next)
		tmp2 = input->next;
	else
		return (0);
	while (tmp2->next)
	{
		if (tmp->val > tmp2->val)
			return (0);
		else
		{
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
	return (1);
}
