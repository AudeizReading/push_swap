/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:16:56 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/06 12:31:18 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_a_inf_med(t_stk *a, t_stk *b, int grp, long *n)
{
	ft_push_stack(&a, &b);
	b->top->grp = grp;
	(*n)++;
	// reflechir comment ne pas se servir de sort two si size a de depart = 5 (-efficace)
//	ft_sort_two(b);
}

t_piv	ft_parse_stack_a(t_stk *a, t_stk *b, int grp)
{
	int		size;
	char	**args;
	t_piv	pivot;

	size = a->size;
	args = ft_stack_to_tab(a);
	pivot = ft_get_median(args, size);
	pivot.q1 = 0;
	while (size--)
	{
		if (a->top->value >= pivot.me)
			ft_rotate_stack(&a);
		else if (a->top->value < pivot.me)
		{
			ft_a_inf_med(a, b, grp, &pivot.q1);
		}
		else if (a->base->value < pivot.me)
		{
			ft_rotate_reverse_stack(&a);
			ft_a_inf_med(a, b, grp, &pivot.q1);
		}
	}
	ft_free_args(args);
	return (pivot);
}

t_stk	*ft_divide_stack_a(t_stk *a, t_stk *b)
{
	static int		grp = 1;
	t_piv			pivot;
	static t_stk	*med;
	t_stk_elt		*elt;

	if (!med)
		med = ft_init_stack("med");
	if (!a)
		return (med);
	if (a->size > 3)
	{
		pivot = ft_parse_stack_a(a, b, grp);
		elt = ft_init_stk_elt(pivot.q1, grp, med->stk_name);
		ft_stkadd_back(&med, elt);
		grp++;
		ft_divide_stack_a(a, b);
	}
	else if (a->size == 2)
		ft_sort_two(a);
	else
		ft_sort_three(a);
	return (med);
}
