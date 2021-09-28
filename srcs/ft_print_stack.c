/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:13:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/09/28 16:01:22 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_elt_stack(t_stk *stack, char *view)
{
	t_stk_elt	*tmp;

	if (!ft_strcmp(view, "top"))
		tmp = stack->top;
	else if (!ft_strcmp(view, "base"))
		tmp = stack->base;
	if (stack->size > 0)
	{
		while (tmp)
		{
			ft_putlnbr(tmp->value);
			ft_putchar(' ');
			ft_putnbr(tmp->grp);
			ft_putchar(' ');
			ft_putendl(tmp->stack_name);
			
			if (!ft_strcmp(view, "top"))
				tmp = tmp->prev;
			else if (!ft_strcmp(view, "base"))
				tmp = tmp->next;
		}
	}


}
void	ft_print_top_stack(t_stk *stack)
{
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
	ft_print_elt_stack(stack, "top");
}

void	ft_print_base_stack(t_stk *stack)
{
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
	ft_print_elt_stack(stack, "base");
}
