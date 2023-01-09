/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:35:54 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/09 11:36:38 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_a_sort(int *tab, int argc)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (tab[i - 1] > tab[i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	i;

	i = 0;
	if (argc < 2)
		return (printf("Error\n"));
	tab_a = malloc(sizeof(int) * argc);
	while (i < argc - 1)
	{
		if (ft_check(argv[i + 1]) != 0)
		{
			tab_a[i] = atoi(argv[i + 1]);
			i++;
		}
		else
			return (printf("Error\n"));
	}
	if (is_a_sort(tab_a, argc) == 1)
		return (0);
}
