/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:12:01 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/04 13:21:42 by alellouc         ###   ########.fr       */
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

typedef struct s_dup
{
	int		i;
	int		j;
	char	*trim_i;
	char	*trim_j;
}				t_dup;

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

/* Errors Handling */
void	ft_puterr(void);

/* Parsing Handling - ps for push_swap */
t_bool		ft_is_valid_ps_args(char **argv);
t_bool		ft_has_duplicate_chars(char **argv);
t_bool		ft_check_arg_is_int(char **args);
char		**ft_parse_args(int argc, char **argv);
void		ft_free_args(char **args);

/* Stack handling */
t_stk		*ft_init_stack(char *stack_name);
t_stk_elt	*ft_init_stk_elt(long value, int grp, char *stk_name);
void		ft_print_elt_stack(t_stk *stack, char *view);
void		ft_print_top_stack(t_stk *stack);
void		ft_print_base_stack(t_stk *stack);
void		ft_print_top_base_stack(t_stk *a);
void		ft_stkadd_back(t_stk **stack, t_stk_elt *elt);
void		ft_stkadd_front(t_stk **stack, t_stk_elt *elt);
void		ft_del_stk_elt(t_stk_elt *elt);
void		ft_pop_clear_stk(t_stk **stack);
void		ft_deq_clear_stk(t_stk **stack);
t_stk_elt	*ft_pop_stack(t_stk **stack);
t_stk_elt	*ft_deq_stack(t_stk **stack);
char		**ft_stack_to_tab(t_stk *stack);

/* Instructions */
void		ft_swap_stack(t_stk *stack);
void		ss(t_stk *a, t_stk *b);
void		ft_push_stack(t_stk **stack_1, t_stk **stack_2);
void		ft_rotate_stack(t_stk **stack);
void		rr(t_stk **a, t_stk **b);
void		ft_rotate_reverse_stack(t_stk **stack);
void		rrr(t_stk **a, t_stk **b);

/* Median */
t_piv		ft_get_median(char **args, int end);

/* Algos */
void		ft_qsort_tab(void *tab[], int l, int r, int (*cmp)(void *, void *));
t_bool		ft_stack_a_is_sort(t_stk *stack);
t_bool		ft_stack_b_is_sort(t_stk *stack);
t_bool		ft_stack_is_sort(t_stk *stack);
t_bool		ft_sort_top_mid_base(t_stk *stack);
t_bool		ft_sort_base_mid_top(t_stk *stack);
t_bool		ft_sort_mid_base_top(t_stk *stack);
t_bool		ft_sort_mid_top_base(t_stk *stack);
t_bool		ft_sort_top_base_mid(t_stk *stack);
t_bool		ft_sort_base_top_mid(t_stk *stack);
//void		ft_sort_three(t_stk *stack);
t_bool		ft_sort_three(t_stk *stack);
t_bool		ft_sort_top_prev(t_stk *stack);
t_bool		ft_sort_prev_top(t_stk *stack);
t_bool		ft_sort_two(t_stk *stack, int grp);
//t_bool		ft_sort_two(t_stk *stack);

/* Launch Program */
int	main(int argc, char **argv);
#endif
