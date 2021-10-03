/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:16:03 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/03 22:16:21 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_sort_top_prev(t_stk *stack)
{
	long	top;
	long	prev;

	if (!stack || stack->size < 2)
		return (e_false);
	top = stack->top->value;
	prev = stack->top->prev->value;
	if (top > prev)
	{
		if (!ft_strcmp(stack->stk_name, "a"))
		{
			ft_swap_stack(stack);
			return (e_true);
		}
		else if (!ft_strcmp(stack->stk_name, "b"))
			return (e_true);
	}
	return (e_false);
}

t_bool	ft_sort_prev_top(t_stk *stack)
{
	long	top;
	long	prev;

	if (!stack || stack->size < 2)
		return (e_false);
	top = stack->top->value;
	prev = stack->top->prev->value;
	if (prev > top)
	{
		if (!ft_strcmp(stack->stk_name, "b"))
		{
			ft_swap_stack(stack);
			return (e_true);
		}
		else if (!ft_strcmp(stack->stk_name, "a"))
			return (e_true);
	}
	return (e_false);
}

t_bool	ft_sort_two(t_stk *stack, int grp)
{
	if (!stack || stack->size < 2)
		return (e_false);
	if (ft_sort_top_prev(stack) || ft_sort_prev_top(stack))
	{
		stack->top->grp = grp;
		stack->top->prev->grp = grp;
		return (e_true);
	}
	return (e_false);
}
