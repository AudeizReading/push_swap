#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - norminette
**   - breaking by mates
*/

/*t_piv	ft_get_median_grp(t_stk *grp)
{
	t_piv	pivot;
	char	**grp_tab;

	if (!grp || !grp->size)
		return ((t_piv){0, 0, 0, 0, 0});
	grp_tab = ft_stack_to_tab(grp);
	pivot = ft_get_median(grp_tab, grp->size);
	ft_free_args(grp_tab);
	return (pivot);
}*/

/*int		ft_set_grp_b(t_stk *b, t_stk *a, int grp, long piv)
{
	if (!a->size || !b->size)
		return (0);
	if (b->top->value >= piv)
	{
		b->top->grp += grp;
		ft_push_stack(&b, &a);
		ft_sort_two(a);
	}
	else if (b->top->value < piv)
	{
		ft_rotate_stack(&b);
		b->base->grp += grp / 10;
		return (1);
	}
	return (0);
}

int		ft_set_grp_a(t_stk *a, t_stk *b, int grp, long piv)
{
	if (!a->size || !b->size)
		return (0);
	if (a->top->value <= piv)
	{
		a->top->grp += grp;
		ft_push_stack(&a, &b);
		ft_sort_two(b);
	}
	else if (a->top->value > piv)
	{
		ft_rotate_stack(&a);
		a->base->grp += grp / 10;
		return (1);
	}
	return (0);
}

void	ft_put_grp_on_top(t_stk *stk, int *i)
{
	t_stk		*info_grp;

	info_grp = ft_get_grp_stk(stk);
	while ((*i)-- && info_grp->top->prev)
	{
		ft_rotate_reverse_stack(&stk);
		ft_sort_two(stk);
	}
}*/

void	ft_divide_stack(t_stk *src, t_stk *dst)
{
	t_piv		pivot;
	t_stk		*current_grp;
	int			size;
	int			i;

	if (!src->size || !dst->size)
		return ;
	current_grp = ft_get_stk_4_med(src, src->top->grp);
	pivot = ft_get_median_grp(current_grp);
	size = current_grp->size;
	i = 0;
	while (size--)
	{
		if (!ft_strcmp(src->stk_name, "a"))
			i += ft_set_grp_a(src, dst, 7770, pivot.me);
		else if (!ft_strcmp(src->stk_name, "b"))
			i += ft_set_grp_b(src, dst, 10000, pivot.q3);
	}
	ft_put_grp_on_top(src, &i);
	ft_pop_clear_stk(&current_grp);
}

void	ft_sort_little_grp(t_stk *src, t_stk *dst, int size)
{
	if (!src->size || !dst->size || size > 3)
		return ;
	if (size == 1)
		ft_push_stack(&src, &dst);
	else if (size == 2)
	{
		ft_sort_two(src);
		ft_push_stack_nb(src, dst, 2);
	}
	else
		ft_sort_3_elts_side_by_side(src, dst);
}

void	ft_sort_big_grp(t_stk *src, t_stk *dst)
{
	ft_divide_stack(src, dst);
	while (!ft_stack_is_sort(dst))
		ft_divide_stack(dst, src);
}

void	ft_sort_little_stack(t_stk *src, t_stk *dst)
{
	if (!src->size || !dst->size)
		return ;
	if (!ft_sort_three(src))
		ft_sort_two(src);
	while (src->size)
		ft_push_stack(&src, &dst);
}

void	ft_sort_big_stack(t_stk *src, t_stk *dst, int size)
{
	if (!src->size || !dst->size || !size)
		return ;
	if (size > 3)
		ft_sort_big_grp(src, dst);
	else
		ft_sort_little_grp(src, dst, size);
}

void	ft_divide_stack_b(t_stk *b, t_stk *a)
{
	t_stk		*current_grp;

	if (!b->size)
		return ;
	current_grp = ft_get_stk_4_med(b, b->top->grp);
	if (!current_grp)
		return ;
	if (ft_stack_is_sort(b))
		while (b->size)
			ft_push_stack(&b, &a);
	else if ((ft_stack_is_sort(a) && !b->size))
		return ;
	else if (b->size < 4)
		ft_sort_little_stack(b, a);
	else if (b->size > 3)
	{
		ft_sort_big_stack(b, a, current_grp->size);
		ft_divide_stack_b(b, a);
	}
	else
		return ;
	ft_pop_clear_stk(&current_grp);
}

t_bool	ft_are_stacks_ready_2_sort(t_stk *a, t_stk *b, char **args)
{
	if (!a || !b)
	{
		if (a)
			ft_pop_clear_stk(&a);
		ft_free_args(args);
		return (e_false);
	}
	return (e_true);
}

t_bool	ft_is_end_bef_begin(t_stk *a, t_stk *b, char **args)
{
	if (a->size < 2 || ft_stack_a_is_sort(a))
	{
		ft_pop_clear_stk(&a);
		ft_pop_clear_stk(&b);
		ft_free_args(args);
		return (e_true);
	}
	return (e_false);
}

int		ft_push_swap(int argc, char **argv)
{
	char	**args;
	t_stk	*a;
	t_stk	*b;
	
	args = ft_parse_args(argc, argv);
	if (!args)
		return (-1);
	a = ft_tab_to_stack(args);
	b = ft_init_stack("b");
	if (!ft_are_stacks_ready_2_sort(a, b, args))
		return (-1);
	if (ft_is_end_bef_begin(a, b, args))
		return (0);
	ft_divide_stack_a(a, b);
	ft_divide_stack_b(b, a);
	if (a)
		ft_pop_clear_stk(&a);
	if (b)
		ft_pop_clear_stk(&b);
	if (args)
		ft_free_args(args);
	return (1);
}

int	main(int argc, char **argv)
{
	int	push_swap;

	push_swap = -1;
	if (argc > 1)
	{
		argv++;
		push_swap = ft_push_swap(argc, argv);
		if (push_swap == -1)
			return (-1);
		else
			return (0);
	}
	else
		ft_puterr();
	return (0);
}
