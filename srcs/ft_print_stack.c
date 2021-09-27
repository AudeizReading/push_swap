/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:13:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/27 15:39:51 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_top_stack(t_stk *stack)
{
	t_stk_elt	*tmp;

	tmp = stack->top;
	ft_putendl("print depuis le top de la stack");
	ft_putstr("size ");
	ft_putnbr(stack->size);
	ft_putstr(" name ");
	ft_putendl(stack->stk_name);
	ft_putstr("top ");
	ft_putlnbr(stack->top->value);
	ft_putstr(" base ");
	ft_putlnbr(stack->base->value);
	ft_putchar('\n');
	while (tmp)
	{
		ft_putlnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->grp);
		ft_putchar(' ');
		ft_putendl(tmp->stack_name);
		tmp = tmp->prev;
	}
}

void	ft_print_base_stack(t_stk *stack)
{
	t_stk_elt	*tmp;

	tmp = stack->base;
	ft_putendl("print depuis la base de la stack");
	ft_putstr("size ");
	ft_putnbr(stack->size);
	ft_putstr(" name ");
	ft_putendl(stack->stk_name);
	ft_putstr("base ");
	ft_putlnbr(stack->base->value);
	ft_putstr(" top ");
	ft_putlnbr(stack->top->value);
	ft_putchar('\n');
	while (tmp)
	{
		ft_putlnbr(tmp->value);
		ft_putchar(' ');
		ft_putnbr(tmp->grp);
		ft_putchar(' ');
		ft_putendl(tmp->stack_name);
		tmp = tmp->next;
	}
}
