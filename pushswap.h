/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:29:40 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/20 16:09:38 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				sim;
	struct s_stack	*next;
}					t_stack;

void	ft_free_input(char **input);
void	ft_five_case(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_three_case(t_stack **stack_a);

int		ft_get_input(int size, t_stack **stack, char **argv, int i);
int		ft_get_input_arg(t_stack **stack, char *str, int *size);
int		set_indexs(t_stack **stack, int size);
int		is_a_sort(t_stack **stack);
int		set_zero(t_stack **stack);
int		ft_check_same(t_stack **stack);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int size);

void	ft_swap(t_stack **stack, char c);
void	ft_swaps(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_rotater(t_stack **stack_a, t_stack **stack_b);
void	ft_rrotate(t_stack **stack, char c);
void	ft_rrotater(t_stack **stack_a, t_stack **stack_b);
void	ft_push_all(t_stack **stack_a, t_stack **stack_b, char c);

#endif
