#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - algo de tri
**   - norminette
**   - stk_elt->grp
*/

// Ce n'est pas obligé de set la pos - c'est juste pour le moment
// Sinon cette fn permet de recalculer la mediane
// Penser a la renommer si je ne m'en sers pas pour les positions
/*t_piv	ft_set_pos_elt_stk(t_stk **stack, char **args)
{
	int			i;
	t_stk_elt	*tmp;
	t_piv		pivot;

	pivot = ft_get_median(args, (*stack)->size);
	i = 0;
	while (args[i])
	{
		tmp = (*stack)->top;
		while (tmp)
		{
			if (ft_atol(args[i]) == tmp->value)
			{
				tmp->grp = i;
				break ;
			}
			else
				tmp = tmp->prev;
		}
		i++;
	}
	return (pivot);
}

t_stk	*ft_get_grp_of_stk(t_stk *stack, long value)
{
	t_stk		*grp;
	t_stk_elt	*elt;
	t_stk_elt	*tmp;

	if (!stack || !value)
		return (NULL);
	grp = ft_init_stack("grp");
	elt = stack->top;
	if (!value)
		return (NULL);
	while (value && stack->size >= value)
	{
		tmp = ft_init_stk_elt(elt->value, elt->grp, elt->stack_name);
		if (!tmp)
		{
			ft_pop_clear_stk(&grp);
			return (NULL);
		}
		ft_stkadd_back(&grp, tmp);
		elt = elt->prev;
		value--;
	}
	return (grp);
}

t_piv	ft_get_median_grp_of_stk(t_stk *stack, long value)
{
	t_stk		*st_me;
	char		**tab_st;
	t_piv		tab_me;

	st_me = ft_get_grp_of_stk(stack, value);
	tab_st = ft_stack_to_tab(st_me);
	tab_me = ft_get_median(tab_st, st_me->size);
	if (!st_me || !tab_st)
		return ((t_piv){0, 0, 0, 0, 0});
	ft_pop_clear_stk(&st_me);
	ft_free_args(tab_st);
	return (tab_me);
}*/

t_stk	*ft_get_grp_stk(t_stk *stack)
{
	t_stk		*grp;
	t_stk_elt	*elt;
	t_stk_elt	*tmp;
	
	grp = ft_init_stack("grp");
	if (!grp || !stack)
		return (NULL);
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->next == NULL || tmp->grp != tmp->next->grp)
		{
			elt = ft_init_stk_elt(0, tmp->grp, grp->stk_name);
			ft_stkadd_front(&grp, elt);
		}
		grp->base->value++;
		tmp = tmp->prev;
	}
	if (!grp->size)
		return (NULL);
	return (grp);
}

t_bool	ft_remains_grp_in_stack(t_stk *stack, int grp)
{
	t_stk_elt	*tmp;

	if (!stack)
		return (e_false);
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->grp == grp)
			return (e_true);
		tmp = tmp->prev;
	}
	return (e_false);
}

t_stk	*ft_get_stk_4_med(t_stk *stack, int grp)
{
	t_stk		*stk_grp;
	t_stk_elt	*elt_grp;
	t_stk_elt	*tmp;

	if (!stack || !stack->size || !grp)
		return (NULL);
	tmp = stack->top;
	stk_grp = ft_init_stack("stk_4_med");
	if (!stk_grp)
		return (NULL);
	while (tmp)
	{
	//	printf("tmp: value [%ld] grp [%d] name [%s]\n", tmp->value, tmp->grp, tmp->stack_name);
		if (tmp->grp == grp)
		{
			elt_grp = ft_init_stk_elt(tmp->value, tmp->grp, stk_grp->stk_name);
			if (!elt_grp)
			{
				ft_pop_clear_stk(&stk_grp);
				return (NULL);
			}
			//ft_stkadd_back(&stk_grp, elt_grp);
			ft_stkadd_front(&stk_grp, elt_grp);
		}
		tmp = tmp->prev;
	}
	if (!stk_grp->size)
		return (NULL);
	return (stk_grp);
}

//void	ft_divide_stack_b_v2(t_stk *b, t_stk *a, t_stk_elt *p_med)
//void	ft_divide_stack_b_v2(t_stk *b, t_stk *a, t_stk *med)
void	ft_divide_stack_b_v2(t_stk *b, t_stk *a)
{
//	t_stk		*med;
	t_stk		*stk_med;
	static t_stk_elt	*p_med;
	t_piv		pivot;
	t_stk		*stk_grp = NULL;
	char		**stk_args;

//	med = NULL;
//	if (!ft_stack_is_sort(a))
//		med = ft_divide_stack_a(a, b);
//	p_med = med->top;
	stk_med = ft_get_grp_stk(b);
//	if (stk_med)
//		ft_print_top_stack(stk_med);
	p_med = stk_med->top;
//	while (stk_med->top)
//		stk_med->top = stk_med->top->prev;
	stk_grp = ft_get_stk_4_med(b, p_med->grp);
	stk_args = ft_stack_to_tab(stk_grp);
	pivot = ft_get_median(stk_args, stk_grp->size);
	if (ft_stack_is_sort(b))
	{
		while (b->size)
			ft_push_stack(&b, &a);
	}
	else if (b->size > 3)
	{
	//	while (ft_remains_grp_in_stack(b, p_med->grp))
	//	{
		//	stk_grp = ft_get_stk_4_med(b, p_med->grp);
		//	stk_args = ft_stack_to_tab(stk_grp);
		//	pivot = ft_get_median(stk_args, stk_grp->size);
			if (stk_grp)
				ft_print_top_stack(stk_grp);
			printf("b->top->value: %ld, b->base->value: %ld\na->top->value: %ld, a->base->value: %ld\n", b->top->value, b->base->value, a->top->value, a->base->value); 
			printf("mediane: %ld, min: %ld, max: %ld, q1: %ld, q3: %ld,  groupe: %d, p_med->value: %ld stk_grp->size: %d\n", pivot.me, pivot.min, pivot.max, pivot.q1, pivot.q3, p_med->grp, p_med->value, stk_grp->size);
		//	ft_sort_three(b);
			
	/*		if (p_med->value > 4)
			{
				printf("\033[32mJe vais galerer a trier cette stack\033[0m\n");
				break ;
			}
			else
			{*/
			if (b->top->grp == p_med->grp && b->top->value >= pivot.me)
			//if (b->top->grp == p_med->grp && b->top->value >= pivot.q3)
		//	if (b->top->value >= pivot.q3)
			{
			/*	if (b->top->value < b->top->prev->value)
				{
					ft_swap_stack(b);
					ft_push_stack(&b, &a);
				}*/
				if (ft_sort_two(b))
					ft_push_stack(&b, &a);
				ft_push_stack(&b, &a);
			//	ft_sort_two(a);
			}
			else if (b->top->grp == p_med->grp && b->top->value < pivot.me)
		//	else if (b->top->grp == p_med->grp && b->top->value < pivot.q3)
			//else if (b->top->value < pivot.q3)
			{
				ft_rotate_stack(&b);
			//	ft_sort_two(a);
			}
			else if (b->base->value >= pivot.me)
		//	else if (b->base->grp == p_med->grp && b->base->value >= pivot.q3)
			{
				ft_rotate_reverse_stack(&b);
				ft_push_stack(&b, &a);
			//	ft_sort_two(a);
			}
		//	else
		//		break ;
		//	}
			if (!ft_remains_grp_in_stack(b, p_med->grp) && p_med->prev)
			{
				p_med = p_med->prev;
			}
			ft_divide_stack_b_v2(b, a);
			ft_pop_clear_stk(&stk_grp);
			ft_free_args(stk_args);
	//	}
	//	if (b->size)
		//	ft_divide_stack_b_v2(b, a, med);
	}
	else if (b->size == 2)
	{
		ft_sort_two(b);
		while (b->size)
			ft_push_stack(&b, &a);
	}
	else if (b->size == 3)
	{
		ft_sort_three(b);
		while (b->size)
			ft_push_stack(&b, &a);
	}
/*	while (p_med->prev)
	{
		t_stk_elt	*tmp;

		tmp = p_med->prev;
		free(p_med);
		p_med = tmp;
	}*/
//	free(elt);
//	free(p_med);
//	ft_pop_clear_stk(&stk_med);
//	ft_pop_clear_stk(&med);
}

// maybe not need get the name for the other fn
void	ft_divide_stack_b(t_stk *b, t_stk *a)
{
	int		size;
	char	**args;
	t_piv	pivot;

	if (!b)
		return ;
	size = b->size;
	args = ft_stack_to_tab(b);
	pivot = ft_get_median(args, size);
	if (b->size > 3)
	{
		if (b->top->value < pivot.me)
			ft_rotate_stack(&b);
		else if (a->top->value >= pivot.me)
		{
			ft_push_stack(&b, &a);
			ft_sort_two(a);
		}
		else if (b->base->value >= pivot.me)
		{
			ft_rotate_reverse_stack(&b);
			ft_push_stack(&b, &a);
			ft_sort_two(a);
		}
		ft_divide_stack_b(b, a);
	}
	else if (b->size == 2)
		ft_sort_two(b);
	else if (b->size == 3)
		ft_sort_three(b);
	else
		return ;
	ft_free_args(args);
}

void	ft_push_swap(t_stk *a, t_stk *b)
{
	//if (!ft_stack_is_sort(a))
	if (!ft_stack_is_sort(a))
	{
		ft_divide_stack_a(a, b);
		ft_divide_stack_b(b, a);
		while (b->size)
			ft_push_stack(&b, &a);
	//	ft_push_swap(a, b);
	}
}

// Si la liste est deja triee en entree -> return 0
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	**args;

		argv++;
		// --------------------PARSE ARGV----------------------------------
		args = ft_parse_args(argc, argv);
		if (!args)
			return (-1);
		// --------------------INIT STACKS---------------------------------
		t_stk		*a;
		t_stk		*b;

		a = ft_tab_to_stack(args);
		b = ft_init_stack("b");
		if (!a || !b)
		{
			if (a)
				ft_pop_clear_stk(&a);
			ft_free_args(args);
			return (-1);
		}
		// --------------------QUIT IF STACK SIZE < 2----------------------
		// --------------------CHECK A IS SORTED---------------------------
		if (a->size < 2 || ft_stack_a_is_sort(a))
		{
			ft_pop_clear_stk(&a);
			ft_pop_clear_stk(&b);
			ft_free_args(args);
			return (0);
		}
		// --------------------ALGORITHM-----------------------------------
	//	ft_sort_two(a);
//		ft_sort_three(a);
//		ft_sort_five(a, b);
		ft_print_top_stack(a);
	//	ft_push_swap(a, b);
	/*	while (!ft_stack_is_sort(a))
		{
			ft_divide_stack_a(a, b);
			ft_divide_stack_b(b, a);
		}
		if (ft_stack_b_is_sort(b))
		{
			while (b->size)
				ft_push_stack(&b, &a);
		}*/
		t_stk	*med;

		med = ft_divide_stack_a(a, b);
		ft_divide_stack_b_v2(b, a);
		//ft_divide_stack_b_v2(b, a, med);

		// set le grp a -1 si c'est sort
	/*	t_stk_elt	*tmp;
		tmp = a->top;
		if (ft_stack_is_sort(a))
		{
			while (tmp)
			{
				tmp->grp = -1;
				tmp = tmp->prev;
			}
		}*/
		if (a->size)
			ft_print_top_stack(a);
		if (b->size)
			ft_print_top_stack(b);
		// --------------------FREE STACK----------------------------------
		if (med)
			ft_pop_clear_stk(&med);
		if (a)
			ft_pop_clear_stk(&a);
		if (b)
			ft_pop_clear_stk(&b);
		// --------------------FREE ARGS-----------------------------------
		// On free le tableau genere par split
		ft_free_args(args);
	}
	else
	{
		// --------------------DISPLAY-------------------------------------
		// only give the prompt back, display nothing if no arg
		ft_puterr();
		return (0);
		// ----------------------------------------------------------------
	}
//	ft_putstr("---------------------------------------\n");
	return (0);
}
