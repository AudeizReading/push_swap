/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_side_by_side_part_01.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:28:58 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/11 15:38:16 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_stack_nb(t_stk *src, t_stk *dst, int nb)
{
	if (!nb || !src->size || !dst->size)
		return ;
	while (nb--)
		ft_push_stack(&src, &dst);
}

void	ft_swap_bef_push_stack(t_stk *src, t_stk *dst, t_bool tgl, int nb)
{
	if (!src->size || !dst->size)
		return ;
	if (tgl)
		ft_swap_stack(dst);
	else
		ft_swap_stack(src);
	ft_push_stack_nb(src, dst, nb);
}

void	ft_sort_descending_order(t_stk *src, t_stk *dst)
{
	if (!src->size || !dst->size)
		return ;
	ft_swap_bef_push_stack(src, dst, e_false, 1);
	ft_swap_bef_push_stack(src, dst, e_false, 1);
	ft_swap_bef_push_stack(src, dst, e_true, 1);
}

void	ft_sort_231_or_213(t_stk *src, t_stk *dst)
{
	if (!src->size || !dst->size)
		return ;
	ft_push_stack(&src, &dst);
	ft_swap_bef_push_stack(src, dst, e_false, 1);
	ft_swap_bef_push_stack(src, dst, e_true, 1);
}

/* 1 2 3 */
t_bool ft_sort_t_p_pp(t_stk *src, t_stk *dst)
{
	long	top;
	long	prev;
	long	pprev;

	if (!src->size || !dst->size)
		return (e_false);
	top = src->top->value;
	prev = src->top->prev->value;
	pprev = src->top->prev->prev->value;
	if (top < prev && top < pprev && prev < pprev)
	{
		if (!ft_strcmp(src->stk_name, "a"))
		{
			ft_push_stack_nb(src, dst, 3);
			return (e_true);
		}
		else if (!ft_strcmp(src->stk_name, "b"))
		{
			ft_sort_descending_order(src, dst);
			return (e_true);
		}
	}
	return (e_false);
}

/* 3 2 1 */
t_bool ft_sort_pp_p_t(t_stk *src, t_stk *dst)
{
	long	top;
	long	prev;
	long	pprev;

	if (!src->size || !dst->size)
		return (e_false);
	top = src->top->value;
	prev = src->top->prev->value;
	pprev = src->top->prev->prev->value;
	if (top > prev && top > pprev && prev > pprev)
	{
		if (!ft_strcmp(src->stk_name, "b"))
		{
			ft_push_stack_nb(src, dst, 3);
			return (e_true);
		}
		else if (!ft_strcmp(src->stk_name, "a"))
		{
			ft_sort_descending_order(src, dst);
			return (e_true);
		}
	}
	return (e_false);
}

/* 2 1 3 */
t_bool ft_sort_p_t_pp(t_stk *src, t_stk *dst)
{
	long	top;
	long	prev;
	long	pprev;

	if (!src->size || !dst->size)
		return (e_false);
	top = src->top->value;
	prev = src->top->prev->value;
	pprev = src->top->prev->prev->value;
	if (top > prev && top < pprev && prev < pprev)
	{
		if (!ft_strcmp(src->stk_name, "a"))
		{
			ft_swap_bef_push_stack(src, dst, e_false, 3);
			return (e_true);
		}
		else if (!ft_strcmp(src->stk_name, "b"))
		{
			ft_sort_231_or_213(src, dst);
		/*	ft_push_stack(&src, &dst);
			ft_swap_bef_push_stack(src, dst, e_false, 1);
			ft_swap_bef_push_stack(src, dst, e_true, 1);*/
			return (e_true);
		}
	}
	return (e_false);
}

/* 2 3 1 */
t_bool ft_sort_pp_t_p(t_stk *src, t_stk *dst)
{
	long	top;
	long	prev;
	long	pprev;

	if (!src->size || !dst->size)
		return (e_false);
	top = src->top->value;
	prev = src->top->prev->value;
	pprev = src->top->prev->prev->value;
	if (top < prev && top > pprev && prev > pprev)
	{
		if (!ft_strcmp(src->stk_name, "b"))
		{
			ft_swap_bef_push_stack(src, dst, e_false, 3);
			return (e_true);
		}
		else if (!ft_strcmp(src->stk_name, "a"))
		{
			ft_sort_231_or_213(src, dst);
			/*ft_push_stack(&src, &dst);
			ft_swap_bef_push_stack(src, dst, e_false, 1);
			ft_swap_bef_push_stack(src, dst, e_true, 1);*/
			return (e_true);
		}
	}
	return (e_false);
}

/* 1 3 2 */
t_bool ft_sort_t_pp_p(t_stk *src, t_stk *dst)
{
	long	top;
	long	prev;
	long	pprev;

	if (!src->size || !dst->size)
		return (e_false);
	top = src->top->value;
	prev = src->top->prev->value;
	pprev = src->top->prev->prev->value;
	if (top < prev && top < pprev && pprev < prev)
	{
		if (!ft_strcmp(src->stk_name, "a"))
		{
			ft_push_stack(&src, &dst);
			ft_swap_bef_push_stack(src, dst, e_false, 2);
			return (e_true);
		}
		else if (!ft_strcmp(src->stk_name, "b"))
		{
			ft_swap_bef_push_stack(src, dst, e_false, 1);
			ft_swap_bef_push_stack(src, dst, e_false, 2);
			return (e_true);
		}
	}
	return (e_false);
}

/* 3 1 2 */
t_bool ft_sort_p_pp_t(t_stk *src, t_stk *dst)
{
	long	top;
	long	prev;
	long	pprev;

	if (!src->size || !dst->size)
		return (e_false);
	top = src->top->value;
	prev = src->top->prev->value;
	pprev = src->top->prev->prev->value;
	if (top > prev && top > pprev && pprev > prev)
	{
		if (!ft_strcmp(src->stk_name, "b"))
		{
			ft_push_stack(&src, &dst);
			ft_swap_bef_push_stack(src, dst, e_false, 2);
			return (e_true);
		}
		else if (!ft_strcmp(src->stk_name, "a"))
		{
			ft_swap_bef_push_stack(src, dst, e_false, 1);
			ft_swap_bef_push_stack(src, dst, e_false, 2);
			return (e_true);
		}
	}
	return (e_false);
}

t_bool	ft_sort_3_elts_side_by_side(t_stk *src, t_stk *dst)
{
	t_bool	cond_1;
	t_bool	cond_2;
	t_bool	cond_3;

	if (!src || !dst || src->size < 3)
		return (e_false);
	cond_1 = ft_sort_t_p_pp(src, dst) || ft_sort_t_pp_p(src, dst);
	if (cond_1)
		return (e_true);
	cond_2 = ft_sort_p_pp_t(src, dst) || ft_sort_p_t_pp(src, dst);
	if (cond_2)
		return (e_true);
	cond_3 = ft_sort_pp_t_p(src, dst) || ft_sort_pp_p_t(src, dst);
	if (cond_3)
		return (e_true);
	return (e_false);
}
