/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:16:56 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/09 13:48:41 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//void	ft_a_inf_med(t_stk *a, t_stk *b, int grp, long *n)
void	ft_a_inf_med(t_stk *a, t_stk *b, int grp)
{
//	if (ft_sort_two(a))
//		ft_push_stack(&a, &b);
	ft_push_stack(&a, &b);
	b->top->grp = grp;
//	(*n)++;
	// reflechir comment ne pas se servir de sort two si size a de depart = 5 (-efficace)
//	if(!ft_sort_three(b))
//		ft_sort_two(b);
}

//t_piv	ft_parse_stack_a(t_stk *a, t_stk *b, int grp)
void	ft_parse_stack_a(t_stk *a, t_stk *b, int grp)
{
	int		size;
	char	**args;
	t_piv	pivot;

	size = a->size;
	args = ft_stack_to_tab(a);
	pivot = ft_get_median(args, size);
//	pivot.q1 = 0;
//	pivot.q3 = 0;
	while (size--)
	{
	//	if (!ft_sort_three(b))
	//		ft_sort_two(b);
	//	if (b->size)
	//		printf("a->top->value: %ld, a->base->value: %ld\nb->top->value: %ld, b->base->value: %ld\n", a->top->value, a->base->value, b->top->value, b->base->value); 
	//	printf("mediane: %ld, min: %ld, max: %ld, q1: %ld, q3: %ld\n", pivot.me, pivot.min, pivot.max, pivot.q1, pivot.q3);
		//if (a->top->value > pivot.q1)
		if (a->top->value >= pivot.me)
		{
			ft_rotate_stack(&a);
		//	ft_sort_three(a);
		}
		else if (a->top->value < pivot.me)
	//	else if (a->top->value <= pivot.q1)
		{
			//ft_a_inf_med(a, b, grp, &pivot.q1);
	//		if (ft_sort_two(a))
	//			ft_push_stack(&a, &b);
			//ft_a_inf_med(a, b, grp, &pivot.q3);
			ft_a_inf_med(a, b, grp);
		}
		else if (a->base->value < pivot.me)
	//	else if (a->base->value <= pivot.q1)
		{
			ft_rotate_reverse_stack(&a);
			//ft_a_inf_med(a, b, grp, &pivot.q1);
			//ft_a_inf_med(a, b, grp, &pivot.q3);
			ft_a_inf_med(a, b, grp);
		}
	}
/*	ft_putstr("\033[35;1m");
	ft_print_top_stack(a);
	if (b->size)
		ft_print_top_stack(b);
	ft_putstr("\033[0m");*/
	ft_free_args(args);
//	return (pivot);
}

//t_stk	*ft_divide_stack_a(t_stk *a, t_stk *b)
void	ft_divide_stack_a(t_stk *a, t_stk *b)
{
	static int		grp = 1;
//	t_piv			pivot;
//	static t_stk	*med;
//	t_stk_elt		*elt;

//	if (!med)
//		med = ft_init_stack("med");
	if (!a)
		//return (med);
		return ;
	if (a->size > 3)
	{
		ft_parse_stack_a(a, b, grp);
		//pivot = ft_parse_stack_a(a, b, grp);
		//elt = ft_init_stk_elt(pivot.q1, grp, med->stk_name);
	//	elt = ft_init_stk_elt(pivot.q3, grp, med->stk_name);
	//	ft_stkadd_back(&med, elt);
		grp++;
		ft_divide_stack_a(a, b);
	}
	else if (a->size == 2)
		ft_sort_two(a);
	else
		ft_sort_three(a);
//	return (med);
}
