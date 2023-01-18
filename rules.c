/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:03:50 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/12 16:33:24 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_swap_a(int *tab)
{
	int	tmp;

	tmp = tab[1];
	tab[1] = tab[0];
	tab[0] = tmp;
	return ("sa");
}

char	*ft_swap_b(int *tab)
{
	int	tmp;

	tmp = tab[1];
	tab[1] = tab[0];
	tab[0] = tmp;
	return ("sb");
}

char	*ft_ss(int *tab_a, int tab_b)
{
	ft_swap_a(tab_a);
	ft_swap_b(tab_b);
	return ("ss");
}

char	*ft_push_a(int *tab_a, int *tab_b, int size)
{
	int	tmp;
	int	i;

	tmp = tab_b[0];
	i = 0;
	while (i <= size)
		tab_b[i] = tab_b[++i];
	i = 0;
	while (size > 0)
	{
		tab_a[size] = tab_a[size - 1];
		size--;
	}
	tab_a[0] = tmp;
}

char	*ft_push_b(int *tab_a, int *tab_b, int size)
{
	int	tmp;
	int	i;

	tmp = tab_a[0];
	i = 0;
	while (i <= size)
		tab_a[i] = tab_a[++i];
	i = 0;
	while (size > 0)
	{
		tab_b[size] = tab_b[size - 1];
		size--;
	}
	tab_b[0] = tmp;
}
