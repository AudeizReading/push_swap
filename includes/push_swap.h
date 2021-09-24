/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:12:01 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/23 17:52:04 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "../libft/libft.h"

typedef t_list	t_stack;

/* Errors Handling */
void	ft_puterr(void);

/* Parsing Handling - ps for push_swap */
t_bool	ft_is_valid_ps_args(char **argv);
t_bool	ft_has_duplicate_chars(char **argv);
t_bool	ft_check_arg_is_int(char **args);

/* Launch Program */
int	main(int argc, char **argv);
#endif
