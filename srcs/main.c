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

/*void	ft_a_inf_med(t_stk *a, t_stk *b, int grp, long *n)
{
	ft_push_stack(&a, &b);
	b->top->grp = grp;
	(*n)++;
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
	static int	grp = 1;
	t_piv		pivot;
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
}*/

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
		t_stk	*med;

		med = ft_divide_stack_a(a, b);
		if (med)
			ft_print_top_stack(med);
		
		if (ft_stack_b_is_sort(b))
		{
			while (b->size)
				ft_push_stack(&b, &a);
		}
/*	*/	else
		{
			// premier palier de b
			// trie jusquau 2 premiers groupes de b
			while (med->top->prev && b->top && med->top->value < 4)
			{
				while (med->top->grp == b->top->grp)
				{
					if (b->top->value < b->top->prev->value)
						ft_swap_stack(b);
					ft_push_stack(&b, &a);
					if (a->top->value > a->top->prev->value)
						ft_swap_stack(a);
				}
				if (med->top->prev)
					med->top = med->top->prev;
			}
			t_stk		*st_me;
			t_stk_elt	*elt;
			t_stk_elt	*tmp;

			st_me = ft_init_stack("st_me");
			elt = b->top;
			while (med->top->value)
			{
				printf("value: %ld\n", med->top->value);
				printf("elt: %ld\n", elt->value);
				tmp = ft_init_stk_elt(elt->value, elt->grp, elt->stack_name);
				ft_stkadd_back(&st_me, tmp);
				elt = elt->prev;
				med->top->value--;
			}
			if (st_me)
				ft_print_top_stack(st_me);
			if (st_me)
				ft_pop_clear_stk(&st_me);
		}

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
	//	if (med)
	//		ft_pop_clear_stk(&med);
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
	ft_putstr("---------------------------------------\n");
	return (0);
}
