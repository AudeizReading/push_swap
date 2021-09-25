/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:12:01 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/25 18:25:10 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_piv
{
	long	min;
	long	max;
	long	me;
	long	q1;
	long	q3;
}				t_piv;

typedef struct s_stk_elt
{
	long				value;
	int					grp;
	char				*stack_name;
	struct s_stk_elt	*prev;
	struct s_stk_elt	*next;
}				t_stk_elt;

typedef struct s_stk
{
	int			size;
	char		*stk_name;
	t_stk_elt	*top;
	t_stk_elt	*base;
}				t_stk;
//typedef t_list	t_stack;

/* Errors Handling */
void	ft_puterr(void);

/* Parsing Handling - ps for push_swap */
t_bool	ft_is_valid_ps_args(char **argv);
t_bool	ft_has_duplicate_chars(char **argv);
t_bool	ft_check_arg_is_int(char **args);
char	**ft_parse_args(int argc, char **argv);
void	ft_free_args(int argc, char **argv, char **args);

/* Stack handling */

/* Instructions */

/* Median */
t_piv	ft_get_median(int argc, char **argv, char **args);

/* Algos */
void	ft_qsort_tab(void *tab[], int l, int r, int (*cmp)(void *, void *));

/* Launch Program */
int	main(int argc, char **argv);
#endif
