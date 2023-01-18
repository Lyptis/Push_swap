/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:29:40 by svanmeen          #+#    #+#             */
/*   Updated: 2023/01/16 15:34:36 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# include "stdio.h"

typedef struct s_pile
{
	int				val;
	int				simp;
	struct s_pile	*next;
}					t_pile;


int		ft_check(char *str);
int		is_a_sort(t_pile *input);
void	*ft_cpy(t_pile *input, t_pile *cpy, int size);

#endif
