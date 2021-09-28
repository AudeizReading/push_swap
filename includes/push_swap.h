/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:12:01 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/28 15:41:37 by alellouc         ###   ########.fr       */
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
t_bool		ft_is_valid_ps_args(char **argv);
t_bool		ft_has_duplicate_chars(char **argv);
t_bool		ft_check_arg_is_int(char **args);
char		**ft_parse_args(int argc, char **argv);
void		ft_free_args(int argc, char **argv, char **args);

/* Stack handling */
t_stk		*ft_init_stack(char *stack_name);
t_stk_elt	*ft_init_stk_elt(long value, int grp, char *stk_name);
void		ft_print_elt_stack(t_stk *stack, char *view);
void		ft_print_top_stack(t_stk *stack);
void		ft_print_base_stack(t_stk *stack);
void		ft_stkadd_back(t_stk **stack, t_stk_elt *elt);
void		ft_stkadd_front(t_stk **stack, t_stk_elt *elt);
void		ft_del_stk_elt(t_stk_elt *elt);
void		ft_pop_clear_stk(t_stk **stack);
void		ft_deq_clear_stk(t_stk **stack);
t_stk_elt	*ft_pop_stack(t_stk **stack);
t_stk_elt	*ft_deq_stack(t_stk **stack);

/* Instructions */

/* Median */
t_piv		ft_get_median(int argc, char **argv, char **args);

/* Algos */
void		ft_qsort_tab(void *tab[], int l, int r, int (*cmp)(void *, void *));

/* Launch Program */
int	main(int argc, char **argv);
#endif
