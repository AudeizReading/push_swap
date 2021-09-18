/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:12:01 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/19 00:05:32 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef t_list	t_stack;

/* Errors Handling */
void	ft_puterr(void);

/* Parsing Handling - ps for push_swap */
int	ft_is_valid_ps_args(char **argv);

/* Launch Program */
int	main(int argc, char **argv);
#endif
