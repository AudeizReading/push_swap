#include "../includes/push_swap.h"

/*   TO-DO LIST 
**   - algo de tri
**   - norminette
**   - stk_elt->grp
*/

// Ce n'est pas obligé de set la pos - c'est juste pour le moment
// Sinon cette fn permet de recalculer la mediane
// Penser a la renommer si je ne m'en sers pas pour les positions
t_piv	ft_set_pos_elt_stk(t_stk **stack, char **args)
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
	while (value)
	{
		tmp = ft_init_stk_elt(elt->value, elt->grp, elt->stack_name);
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
	ft_pop_clear_stk(&st_me);
	ft_free_args(tab_st);
	return (tab_me);
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

void	ft_divide_stack_b_v2(t_stk *b, t_stk *a)
{
	t_stk	*med;
	t_stk_elt	*p_med;

	med = ft_divide_stack_a(a, b);
	p_med = med->top;
	if (b->size > 3)
	{
		while (ft_remains_grp_in_stack(b, p_med->grp))
		{
			if (b->top->grp == p_med->grp)
			ft_push_stack(&b, &a);
		}
		//ft_divide_stack_b_v2(b, a);
	}
	else if (b->size == 2)
	{
		ft_sort_three(b);
		while (b->size)
			ft_push_stack(&b, &a);
	}
	else if (b->size == 3)
	{
		ft_sort_two(b);
		while (b->size)
			ft_push_stack(&b, &a);
	}

/*	t_stk		*med;
	static t_stk_elt	*p_med;
	t_piv		tab_me;
	int			i;

	med = ft_divide_stack_a(a, b);
	p_med = med->top;
	i = 0;
	tab_me = ft_get_median_grp_of_stk(b, p_med->value);
	while (p_med->value--)
	{
		printf("p_med->value: %ld, p_med->grp: %d, me: %ld\n", p_med->value, p_med->grp, tab_me.me);
		printf("b->top: %ld, b->base: %ld, a->top: %ld, a->base: %ld\n", b->top->value, b->base->value, a->top->value, a->base->value);
		if (ft_remains_grp_in_stack(b, p_med->grp))
			printf("Il reste des elts du grp dans la stack\n");
		if (b->top->value < tab_me.me)
		{
			ft_rotate_stack(&b);
			i++;
		}
		else if (b->top->value >= tab_me.me)
		{
			ft_push_stack(&b, &a);
			ft_sort_two(a);
		}
		//else if (b->base->value >= tab_me.me || i)
		else if (b->base->value >= b->top->value)
		{
			ft_rotate_reverse_stack(&b);
			ft_push_stack(&b, &a);
			ft_sort_two(a);
		//	i--;
		}
		if (!p_med->value && i)
		{
			while (i--)
			{
			//	ft_sort_three(b);
				ft_rotate_reverse_stack(&b);
				if (ft_sort_two(b))
				{
					if (b->top->grp == p_med->grp)
					{
						ft_push_stack(&b, &a);
						ft_sort_two(a);
					}
					else
						ft_rotate_stack(&b);
				}
		//		p_med->value++;
			//	ft_sort_two(a);
			}
		}
		if (p_med->prev && !p_med->value)
		{
			p_med = p_med->prev;
		//	ft_divide_stack_b_v2(b, a);
			tab_me = ft_get_median_grp_of_stk(b, p_med->value);
		}
	}
	ft_pop_clear_stk(&med);*/
}

void	ft_divide_stack_b(t_stk *b/*, t_stk *med*/, t_stk *a)
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
	//	while(!ft_stack_is_sort(a))
			ft_divide_stack_b_v2(b, a);
		//ft_divide_stack_b_v2(b, a);
	/*	t_stk	*med;

		med = ft_divide_stack_a(a, b);
		if (med)
			ft_print_top_stack(med);
		
		if (ft_stack_b_is_sort(b))
		{
			while (b->size)
				ft_push_stack(&b, &a);
		}*/
/*	*//*	else
		{
			// premier pallier de b
			// trie jusquau 2 premiers groupes de b
			t_stk_elt	*p_med;

			p_med = med->top;
			while (p_med->prev && b->top && p_med->value < 4)
			{
				while (p_med->grp == b->top->grp)
				{
					if (b->top->value < b->top->prev->value)
						ft_swap_stack(b);
					ft_push_stack(&b, &a);
					if (a->top->value > a->top->prev->value)
						ft_swap_stack(a);
				}
				if (p_med->prev)
				{
					p_med = p_med->prev;
					printf("p_med->value: %ld, p_med->grp: %d\n", p_med->value, p_med->grp);
				}
			}
			ft_divide_stack_b(b, a);
	//		ft_sort_three(b);
		//	if (ft_stack_b_is_sort(b))
		//	{
			//	while (b->size)
			//		ft_push_stack(&b, &a);
		//	}
			ft_divide_stack_a(a, b);
			//if (ft_stack_b_is_sort(b))
			//{
			//	while (b->size)
			//		ft_push_stack(&b, &a);
			//}
			ft_divide_stack_b(b, a);
			t_piv		tab_me;

			tab_me = ft_get_median_grp_of_stk(b, p_med->value);
		//	if (tab_me.me)
		//		printf("me: %ld\n", tab_me.me);
			while (p_med->value--)
			{
				if (b->top->grp == p_med->grp)
				{
			//		tab_me = ft_get_median_grp_of_stk(b, p_med->value);
					if (tab_me.me)
						printf("b->top:%ld\tme: %ld\n", b->top->value, tab_me.me);
					if (b->top->value >= tab_me.me)
					{
						ft_push_stack(&b, &a);
						ft_sort_two(a);
					}
					else if (b->top->value < tab_me.me)
					{
						ft_rotate_stack(&b);
					}
					else if (b->base->value >= tab_me.me)
					{
						ft_rotate_reverse_stack(&b);
						ft_push_stack(&b, &a);
						ft_sort_two(a);
					}
				}
			//	p_med->value--;
			//	if (!p_med->value && b->top->grp == p) 
				if (!p_med->value)
					if (p_med->prev)
						p_med = p_med->prev;
				printf("p_med->value: %ld\tp_med->grp: %d\n", p_med->value, p_med->grp);
			}
		}*/

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
//		if (med)
//			ft_pop_clear_stk(&med);
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
