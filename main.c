/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:35:54 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/16 15:36:03 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_get_input(int argc, t_pile *input, char **argv)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = input;

	while (i < argc - 1)
	{
		if (ft_check(argv[i + 1]) != 0)
		{
			tmp->val = ft_atoi(argv[i + 1]);
			tmp->next = malloc(sizeof(t_pile));
			tmp = tmp->next;
			i++;
		}
		else
			return (1);
	}
	tmp->next = NULL;
}

int	main(int argc, char **argv)
{
	t_pile	*input;
	t_pile	*pile_a;
	int		i;

	i = 0;
	if (argc < 2)
		return (printf("Error\n"));
	input = malloc(sizeof(t_pile));
	if(ft_get_input(argc, input, argv) == 1)
	{
		return (printf("Error"));
		//free()
	}
	if (is_a_sort(input) == 1)
		return (0);
	pile_a = malloc(sizeof(t_pile));
	ft_cpy(input, pile_a, argc - 1);
	//i = 0;
	while (input->next != NULL)
	{
		printf("%d ", input->simp);
		input = input->next;
	}
}
